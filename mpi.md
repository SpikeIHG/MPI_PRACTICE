## 解决了如何添加 mpi共享库的问题 首先在cpp.properties.json 里面添加文件includepath 加一个 这个也可以通过快速修复来完成
## 同时由于 mpi 需要脚本进行编译 所以需要更改编译器 为 mpic++
# 然后就是 似乎要选择如何同步 git 可以直接在终端里面选择 我们选择就是 git config pull.rebase false 就是默认操作
***然后还有就是要使.o 文件进入指定的文件夹修改的是task.json 文件 注意不同的功能区别***



### 一个重要的解决include 实在 cpp_properties 这个文件夹里面 然后具体的文件 可以 find /usr -name "example" 
