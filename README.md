# GuessNumber
GuessNumber - Educational and just-for-fun project on С++

## Dependencies
* [GTest](https://github.com/google/googletest)

## Build
```shell
vcpkg install gtest
vcpkg integrate install

cd GuessNumber
mkdir build && cd build

cmake .. -DCMAKE_TOOLCHAIN_FILE="Path to vcpkg.cmake"
cmake --build .
```

## Usage 
```Shell
./guess_number.exe
```

## Testing
```shell
ctest
```
