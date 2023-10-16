---
title: Nodejs安装 & Hexo搭建及使用 & Git安装及使用
date: 2023-10-14 20:29:35
tags: [安装配置, 使用教程]
categories: 安装
cover: https://storage.sangniao.com/uploads/article/000/00/00/13/9eae3436aeee4d318222b09eaafb2489.jpeg
---



# NodeJS 安装 & 环境搭建

> **NodeJS** 的安装说实在搞得头大，总是莫名其妙的出现各种问题，像 cnpm 系统不识别之类的，总之就是非常头大，不过还好，总算是找到了一个没有任何报错的安装方法→ [BV19F411t7zX](https://www.bilibili.com/video/BV19F411t7zX/?vd_source=b4e7a930b6168115887cecaf26f330e6)。

### 下载 NodeJS

[NodeJS 官网](https://nodejs.cn/download/) 下载对应版本，这里使用的是 Windows-64 安装包

[![image.png](https://i.postimg.cc/SR9yCDxD/image.png)](https://postimg.cc/rR8XLGWr)

解压后新建两个文件夹：用来放缓存文件的 `node_cache` 和用来放系统全局文件的 `node_global`

[![image.png](https://i.postimg.cc/1tpCFFZD/image.png)](https://postimg.cc/MMpm2vHG)

### 配置环境变量

在**系统变量**中新建一个  `NODE_HOME`

[![image.png](https://i.postimg.cc/R00Yv2nm/image.png)](https://postimg.cc/YvJR3n3D)

然后再从**系统变量**的 `PATH` 中添加下面三段

```
%NODE_HOME%
%NODE_HOME%\node_cache
%NODE_HOME%\node_global
```

[![image.png](https://i.postimg.cc/28z7phWR/image.png)](https://postimg.cc/z3cgKLp0)

以上工作完成后，再终端中输入 `node -v`、`npm -v` 测试环境变量是否配置成功

](https://postimg.cc/VSwc3PSf)

### 配置 npm & cnpm

```
// 配置 npm 全局
npm config set prefix "node_global 的路径"
// 配置 npm 缓存
npm config set cache "node_cache 的路径"
// 国内下载慢所以用阿里的镜像下载
npm config set registry https://registry.npm.taobao.org
```

没有报错就说明已经成功配置了，然后就可以下载镜像文件了

```
npm install -g cnpm
```

安装成功后输入 `cnpm -v` 测试是否成功，在 node_global 文件夹下也可以看到 cnpm 文件，安装到此完成！

----

# Hexo 安装 & 使用

### Hexo 安装

> Hexo 官网有提供的详尽的 [安装使用文档](https://hexo.io/zh-cn/docs/)，需要注意的是，Hexo 需要搭配 Git 和 NodeJS 使用，在安装之前需要把前面两个提前安装！也可以参考→[BV1Yb411a7ty](https://www.bilibili.com/video/BV1Yb411a7ty/?vd_source=b4e7a930b6168115887cecaf26f330e6)

Hexo 使用的是命令行进行操作，首先**安装 Hexo**，hexo -v 测试安装

```
cnpm install -g hexo-cli
```

在博客文件夹根目录下**初始化 Hexo**

```
hexo init
npm install	// 初始化成功了就不需要再执行这步了
```

### Hexo 使用

|     功能     |    代码    |   代码全称    |
| :----------: | :--------: | :-----------: |
| 启动本地预览 |   hexo s   |  hexo server  |
| 清理本地缓存 | hexo clean |  hexo clean   |
| 生成HTML文件 |   hexo g   | hexo generate |
|  推送到云端  |   hexo d   |  hexo deploy  |
| 创建新的文章 |   hexo n   |   hexo new    |

> 标签 Tag：多个标签用 `[ a, b, c ]` 分隔开

### Blog 部署到 Github

首先再本目录下安装部署插件

```
cnpm install --save hexo-deployer-git
```

插件装完后去 `-config.yml` 里进行必要配置！在文件最下面修改 `# Deployment` 里面的信息

```
type: git
repo: https://github.com/choomoray/choomoray.github.io.git
branch: blog	// 可以不写，默认保存到 Github 仓库的 master 分支中
```

[![image.png](https://i.postimg.cc/1RrDbQcm/image.png)](https://postimg.cc/144gNbj2)



# Git 使用

> Git的使用在以后用到的时候再进行更新，目前仅为上传不同名文件夹内容到远程仓库的不同分支中，方法也非常简单，使用Github桌面端就可以进行操作，把仓库克隆到要上传的文件夹父目录，克隆完成后把名字一改再重新寻址就可以了

----

