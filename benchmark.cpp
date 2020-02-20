#include <iostream>
#include <stdint.h>
#include <time.h>
#include <math.h>

int main(){
    
    clock_t intTime;
    intTime = clock();
    //32-bit integer operation benchmark
    int32_t n = 0;
    int32_t m = 0;
    int32_t o = 0;
    for(int64_t i = 0; i < 100000000000; i++){
        n = 2 + 2;
    }
    for(int64_t j = 0; j < 50000000000; j++){
        m = 2 * 2;
    }
    for(int64_t k = 0; k < 20000000000; k++){
        o = 2 / 2;
    }
    intTime = clock() - intTime;
    double intTime_taken = ((double)intTime)/CLOCKS_PER_SEC;
    std::cout << intTime_taken << " seconds" << std::endl;

    clock_t floatTime;
    floatTime = clock();
    //32-bit float operation benchmark
    float x = 0.0;
    float y = 0.0;
    float z = 0.0;
    for(int64_t a = 0; a < 100000000000; a++){
        x = 2.0 + 2.0;
    }
    for(int64_t b = 0; b < 50000000000; b++){
        y = 2.0 * 2.0;
    }
    for(int64_t c = 0; c < 20000000000; c++){
        z = 2.0 / 2.0;
    }
    floatTime = clock() - floatTime;
    double floatTime_taken = ((double)floatTime)/CLOCKS_PER_SEC;
    std::cout << floatTime_taken << " seconds" << std::endl;

    //memory benchmark
    clock_t arrayTime;
    arrayTime = clock();
    int64_t benchArr[1000000];
    int64_t read;
    //write in elements
    for(int e = 0; e < 5000; e++){
        for(int64_t f = 0; f < 1000000; f++){
            benchArr[f] = f;
        }
    }
    //read elements
    for(int g = 0; g < 5000; g++){
        for(int64_t h = 0; h < 1000000; h++){
            read = benchArr[h];
        }
    }
    arrayTime = clock() - arrayTime;
    double arrayTime_taken = ((double)arrayTime)/CLOCKS_PER_SEC;
    std::cout << arrayTime_taken << " seconds" << std::endl;
    return 0;
}