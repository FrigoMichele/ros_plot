
cd ../build
cmake -DCMAKE_BUILD_TYPE=Release -S .. -B .
cmake --build . -j4
cd ../scripts