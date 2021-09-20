# SQLBackupToFTPServer

## Building:

### Release build:

```bash
mkdir build
cd ./build
cmake ..
make -j <job count>
```

### Build unit tests.
```bash
mkdir build
cd ./build
cmake -DBUILD_UNIT_TESTS=YES ..
make -j <job count>
```
