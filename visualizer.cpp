#include<raylib.h>

#include "algos/algos.h"

// defning global random number generation func
auto setup_randgen(int high, int low=1){

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); // stting up random seed engine
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribute(low, high);
    
    return bind(distribute, generator);
}


void PopulateVec(std::vector<int> &vec, auto GetRandVal){
    for (int &i: vec) i = GetRandVal();
}

int main(void){

    // Defining window geometry, caption, etc.
    const int screenWidth = 800, screenheight = 500; //window dimensions
    std::string title = "Sorting Visualiser ";
    const int targetframes = 60;
    std::thread sort_th;

    Color bgcolor{0,0,0,255}, txtcolor{0,180,0,255}, greyrect{250,250,250,125}, greenrect{150,250,150,225};

    // Support vars
    int itemwidth = 1, itemcount = screenWidth/itemwidth;
    unsigned short current_algo_index = 0;

    std::vector<int> vec(itemcount,0);

    // Defining draw components
    label l1{"[R]andomize  [S]ort  [C]ancel  [N]ext  [P]revious",10,10,20};

    // Setting up window components
    SetTraceLogLevel(4);
    InitWindow(screenWidth, screenheight, title.c_str());

    if(!IsWindowReady()) return 1;

    SetTargetFPS(targetframes); // setting-up target frames

    // Mainloop
    while(!WindowShouldClose()){

        // key-bindings
        if (IsKeyPressed(KEY_R) && !IsThreadAlive){
            IsVectorSorted = 0;
            PopulateVec(vec, setup_randgen(screenheight-50));
        }
        else if (IsKeyPressed(KEY_S)){
            if (!IsThreadAlive) {
                IsThreadAlive = 1;
                IsVectorSorted = 0;
                sort_th = std::thread(algo_defs[current_algo_index], std::ref(vec));
                sort_th.detach();
            }
            // IsSorted(vec);
        }
        else if (IsKeyPressed(KEY_C) && !IsAborted){
            IsAborted = 1;
        }
        else if (IsKeyPressed(KEY_N)){
            current_algo_index = (unsigned short)(current_algo_index+1)%algo_count;
            SetWindowTitle((title+"- "+algo_types[current_algo_index]).c_str());
        }
        else if (IsKeyPressed(KEY_P)){
            current_algo_index = (unsigned short)(current_algo_index-1)%algo_count;
            SetWindowTitle((title+"- "+algo_types[current_algo_index]).c_str());
        }
        else if (IsKeyPressed(KEY_Q)){
            std::cout<<IsAborted<<" "<<IsThreadAlive<<std::endl;
        }
        


        // rendering
        BeginDrawing();
        ClearBackground(bgcolor);

        DrawFPS(GetScreenWidth()-100, 10);
        DrawText(l1.name, l1.x, l1.y, l1.size, txtcolor);

        for(int i = 0;i < itemcount;i++){
            DrawRectangle(itemwidth*i,(screenheight-vec[i]),itemwidth,vec[i],(IsVectorSorted)?greenrect:greyrect);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}