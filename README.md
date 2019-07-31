# protobuf-c

## 1、介绍

Google 的 prototol buffer 一种轻便高效的数据存储格式，可以很方便地把结构化的数据用二进制的格式保存起来，很适合高效地数据存储和传输。

## 2、项目说明

| 名称     | 说明       |
| -------- | ---------- |
| doc     | 文档目录   |
| examples | 例子目录   |
| src      | 源代码目录 |

## 3、如何使用 protobuf-c

使用 protobuf-c 需要在 RT-Thread 的包管理器中选择它，具体路径如下：

```
RT-Thread online packages
  miscellaneous packages  --->
      [*] libann: a light-weight ANN library, capable of training, saving and loading  models.
```

然后让 RT-Thread 的包管理器自动更新，或者使用 `pkgs --update` 命令更新包到 BSP 中。

## 4、注意事项

- 如果使用了 encode_decode_file 例程，需要打开文件系统支持

## 5、感谢

protobuf-c: [https://github.com/protobuf-c/protobuf-c](https://github.com/protobuf-c/protobuf-c)

## 6、联系方式

- 维护：Wu Han
- 主页：http://wuhanstudio.cc
- 邮箱：wuhanstudio@hust.edu.cn