
cd ../build
cmake -DCMAKE_BUILD_TYPE=Debug -S .. -B .
cmake --build . -j4
cd ../scripts