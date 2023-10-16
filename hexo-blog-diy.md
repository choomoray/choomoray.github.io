---
title: 静态博客 Hexo 的搭建与使用
date: 2023-10-14
updated: 2023-10-16
tags: 
  - 安装配置
  - 使用教程
  - Blog
  - Hexo
  - NodeJS
  - Git
  - Tips
categories: 
  - 笔记
cover: ../images/2023/hexo_blog_diy/cover.webp
---



> **Hexo** + **Github** 静态博客搭建，好处是不需要购买域名、服务器资源，也不需要繁琐的备案，从难易程度上静态博客的搭建是比动态的要简单些的，唯一的坏处可能就是在其他设备上只能访问不能修改吧，问题不大。

Hexo 静态博客安装需要以下几个必要插件：`NodeJS`、`Git`、`Hexo`

NodeJS 是 Hexo 的必要插件，而 Git 是推送到 Github 的必要插件



# NodeJS 安装 & 环境搭建

> **NodeJS** 的安装说实在搞得头大，总是莫名其妙的出现各种问题，像 cnpm 系统不识别之类的，总之就是非常头大，不过还好，总算是找到了一个没有任何报错的安装方法→ [BV19F411t7zX](https://www.bilibili.com/video/BV19F411t7zX/?vd_source=b4e7a930b6168115887cecaf26f330e6)。



## 下载 NodeJS

[NodeJS 官网](https://nodejs.cn/download/) 下载对应版本，这里使用的是 Windows-64 安装包

![NodeJS官网下载对应版本](../images/2023/hexo_blog_diy/1.png)

解压后新建两个文件夹：用来放缓存文件的 `node_cache` 和用来放系统全局文件的 `node_global`



## 配置环境变量

在**系统变量**中新建一个  `NODE_HOME`

![](../images/2023/hexo_blog_diy/2.png)

然后再从**系统变量**的 `PATH` 中添加下面三段

```
%NODE_HOME%
%NODE_HOME%\node_cache
%NODE_HOME%\node_global
```

以上工作完成后，再终端中输入 `node -v`、`npm -v` 测试环境变量是否配置成功



## 配置 npm & cnpm

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

安装成功后输入 `cnpm -v` 测试是否成功，在 node_global 文件夹下也可以看到 cnpm 文件，NodeJS 的安装配置到此完成！

----





# Git 安装 & 使用

> [Git](https://git-scm.com/downloads) 直接下载对应版本安装即可，一直下一步傻瓜式安装



## Git 使用

> Git的使用在以后用到的时候再进行更新，目前仅为上传不同名文件夹内容到远程仓库的不同分支中，方法也非常简单，使用Github桌面端就可以进行操作，把仓库克隆到要上传的文件夹父目录，克隆完成后把名字一改再重新寻址就可以了

----





# Hexo 安装 & 使用

## Hexo 安装

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



## Hexo 基本操作

|     功能     |    代码    |   代码全称    |
| :----------: | :--------: | :-----------: |
| 启动本地预览 |   hexo s   |  hexo server  |
| 清理本地缓存 | hexo clean |  hexo clean   |
| 生成HTML文件 |   hexo g   | hexo generate |
|  推送到云端  |   hexo d   |  hexo deploy  |
| 创建新的文章 |   hexo n   |   hexo new    |



## 文章「头文件」

使用 `hexo new` 创建新的文章，Hexo 会自动帮我们在文章中生成一个「头文件」，包含各种文章信息：文章标题、创建时间、修改时间、标签、分类、封面等，需要自己进行完善，[password](#jump_文章加密) 不属于 Hexo 自带，需要自行安装使用

```
title: 静态博客 Hexo 的搭建与使用教程	// 文章标题
date: 2023-10-14	// 创建时间
updated: 2023-10-16	// 修改时间
tags: 			// 标签，多个标签也可以用[a,b]
  - 安装配置
  - 使用教程	
categories: 		// 分类
	- 学习	// 父类
	- 心得	// 子类
cover: https://url	// 文章封面
password: 12345		// 密码
```



## Blog 部署到 Github

首先再本目录下安装部署插件

```
cnpm install --save hexo-deployer-git
```

插件装完后去 `_config.yml` 里进行必要配置！在文件最下面修改 `# Deployment` 里面的信息

```
type: git
repo: https://github.com/choomoray/choomoray.github.io.git
branch: blog	// 可以不写，默认保存到 Github 仓库的 master 分支中
```

----





# Hexo 主题 & 美化

在 [Butterfly](https://github.com/jerryc127/hexo-theme-butterfly) 下载好压缩包，解压到 Theme 文件夹，然后在 `_config.yml` 里把默认的 Theme 替换成需要修改的主题文件夹名就大功告成了！



> 主题美化可以参考作者写的[详细文档](https://butterfly.js.org/)



## 网站基本信息

在博客根目录的`主配置文件`里修改网站的基础资料，标题、副标题、个人资料等

```yaml
# Site
title: CHOOMORAY
subtitle: ''
description: ''
keywords:
author: choomoray
language: zh-CN
timezone: ''
```



### 头像

修改 `主配置文件`

````yaml
avatar:
  img: /img/avatar.png	# 图片目录
  effect: true		# 头像会一直转圈
````



## 导航栏

### 基础参数设置

```yaml
nav:
  logo: 			# image							
  display_title: true		# 是否显示网站标题
  fixed: false 			# 固定网站标题
```



### 顶栏菜单目录

> `menu` 只是控制是否显示，**标签、分类**需要单独创建 Page 来显示，具体操作在[功能补充页](#jump_功能补充页) 

```yaml
menu:	# Menu 目录
  首页: / || fas fa-home
  时间轴: /archives/ || fas fa-archive
  标签: /tags/ || fas fa-tags
  分类: /categories/ || fas fa-folder-open
  ME: /diary/ || fas fa-link
  ...
```



### 顶栏图片

| 配置             | 解释                                                         |
| :--------------- | :----------------------------------------------------------- |
| index_img        | 主页的 top_img                                               |
| default_top_img  | 默认的 top_img，当页面的 top_img 没有配置时，会显示 default_top_img |
| archive_img      | 归档页面的 top_img                                           |
| tag_img          | tag 子页面 的 默认 top_img                                   |
| tag_per_img      | tag 子页面的 top_img，可配置每个 tag 的 top_img              |
| category_img     | category 子页面 的 默认 top_img                              |
| category_per_img | category 子页面的 top_img，可配置每个 category 的 top_img    |



## 代码块

> 主题提供了几种代码块可供选择，修改关键词 `highlight_theme`
>
> 还包括代码块的复制（ `highlight_copy` ）、展开（ `highlight_shrink` ）、换行（`code_word_wrap`  ）以及高度限制（ `highlight_height_limit` ）



## 内容

### 文章封面

> 在写文章时添加，在 `Front-matter` 添加 `cover: url`

```yaml
title: Hexo Butterfly 主题美化 & 功能补充
date: 2023-10-16 12:23:52
tags: [Hexo, Butterfly]
categories: DIY
cover: https://cdn.pixabay.com/photo/2023/09/07/14/26/cat-8239223_1280.png
```





# 功能补充

## <span id="jump_功能补充页">标签页 & 分类页</span>

模板默认是没有标签页和分类页的，需要我们自己添加，非常简单，在命令行中分别敲入下面两行代码，`source` 目录下就会自动生成对应文件夹，里面的 index.md 就是对应文件

```yaml
hexo new page tags
hexo new page categories
```



## 搜索功能

非常实用的搜索功能，但是 Hexo 原生并不支持，需要安装依赖：

```yaml
npm install hexo-generator-search --save
```

修改`主配置文件`，添加如下内容：

```yaml
search:	# 搜索
  path: search.xml
  field: post
  content: true
  template: ./search.xml
```

在主题中开启搜索，在`主题配置文件`添加以下内容：

```yaml
local_search:
-  enable: false
+  enable: true
```



## <span id='jump_文章加密'>文章加密</span>

文章加密同样需要依赖支持：

```yaml
npm install --save hexo-blog-encrypt
```

在`主配置文件`中添加下面代码：

```yaml
# 安全
encrypt: # hexo-blog-encrypt
  abstract: 这里有东西被加密了，需要输入密码查看哦。
  message: 您好, 这里需要密码.
  tags:
  - {name: tagName, password: 密码A}
  - {name: tagName, password: 密码B}
  template: <div id="hexo-blog-encrypt" data-wpm="{{hbeWrongPassMessage}}" data-whm="{{hbeWrongHashMessage}}"><div class="hbe-input-container"><input type="password" id="hbePass" placeholder="{{hbeMessage}}" /><label>{{hbeMessage}}</label><div class="bottom-line"></div></div><script id="hbeData" type="hbeData" data-hmacdigest="{{hbeHmacDigest}}">{{hbeEncryptedData}}</script></div>
  wrong_pass_message: 抱歉, 这个密码看着不太对, 请再试试.
  wrong_hash_message: 抱歉, 这个文章不能被校验, 不过您还是能看看解密后的内容.
```

在文章中使用加密，在「头文件」中添加 `password` 关键词即可：

```yaml
password: 123456
```

![](../images/2023/hexo_blog_diy/3.png)



## 插入本地图片

> [官方文档](https://hexo.io/zh-cn/docs/asset-folders)简单易懂，要比网上一个答案到处抄来的靠谱（花了好几个小时也没成功）。总结一下：

首先要打开`主配置文档`中的`允许使用本地静态资源`：

```yaml
post_asset_folder: true
```

然后在`source`文件夹下创建`images`文件，把图片放入images文件夹就可以了，引用格式如下：

```yaml
![图片描述](../images/....../1.png)
```

需要注意的是：图片路径必须使用`/`

----

