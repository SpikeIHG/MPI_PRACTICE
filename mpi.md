## 解决了如何添加 mpi共享库的问题 首先在cpp.properties.json 里面添加文件includepath 加一个 这个也可以通过快速修复来完成
## 同时由于 mpi 需要脚本进行编译 所以需要更改编译器 为 mpic++