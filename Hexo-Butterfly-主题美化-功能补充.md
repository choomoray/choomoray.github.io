---
title: Hexo Butterfly 主题美化 & 功能补充
date: 2023-10-16 12:23:52
tags: [Hexo, 主题, DIY]
cover: https://cdn.pixabay.com/photo/2023/09/07/14/26/cat-8239223_1280.png
---

## 主题模板安装

> 在 [Butterfly Github](https://github.com/jerryc127/hexo-theme-butterfly) 下载好压缩包，解压到 Theme 文件夹，然后在 `_config.yml` 里把默认的 Theme 替换成需要修改的主题文件夹名就大功告成了！

## 主题美化

> 主题美化可以参考作者写的[详细文档](https://butterfly.js.org/)

### 网站基本信息

> 在博客根目录的 `_config.yml` 文件里修改网站的基础资料，标题、副标题、个人资料等

[![image.png](https://i.postimg.cc/VvkBtMsH/image.png)](https://postimg.cc/ph3FbmFD)

#### 头像

修改 `主配置文件`

````yaml
avatar:
  img: /img/avatar.png	# 图片目录
  effect: true		# 头像会一直转圈
````



### 导航栏

#### 基础参数设置

```yaml
nav:
  logo: 			# image							
  display_title: true		# 是否显示网站标题
  fixed: false 			# 固定网站标题
```

#### 顶栏菜单目录

> `menu` 只是控制是否显示，**标签、分类**需要单独创建 Page 来显示，具体操作在[功能补充页](#jump_功能补充页) 

[![image.png](https://i.postimg.cc/nLw91D3R/image.png)](https://postimg.cc/d7r0sLPr)

#### 顶栏图片

| 配置             | 解释                                                         |
| :--------------- | :----------------------------------------------------------- |
| index_img        | 主页的 top_img                                               |
| default_top_img  | 默认的 top_img，当页面的 top_img 没有配置时，会显示 default_top_img |
| archive_img      | 归档页面的 top_img                                           |
| tag_img          | tag 子页面 的 默认 top_img                                   |
| tag_per_img      | tag 子页面的 top_img，可配置每个 tag 的 top_img              |
| category_img     | category 子页面 的 默认 top_img                              |
| category_per_img | category 子页面的 top_img，可配置每个 category 的 top_img    |



### 代码块

> 主题提供了几种代码块可供选择，修改关键词 `highlight_theme`
>
> 还包括代码块的复制（ `highlight_copy` ）、展开（ `highlight_shrink` ）、换行（`code_word_wrap`  ）以及高度限制（ `highlight_height_limit` ）

### 内容

#### 文章封面

> 在写文章时添加，在 `Front-matter` 添加 `cover: url`

```yaml
title: Hexo Butterfly 主题美化 & 功能补充
date: 2023-10-16 12:23:52
tags: [Hexo, Butterfly]
categories: DIY
cover: https://cdn.pixabay.com/photo/2023/09/07/14/26/cat-8239223_1280.png
```





## 功能补充

### <span id="jump_功能补充页">标签页 & 分类页</span>

> 模板默认是没有标签页和分类页的，需要我们自己添加，非常简单，在命令行中分别敲入下面两行代码，`source` 目录下就会自动生成对应文件夹，里面的index.md就是对应文件

```yaml
hexo new page tags
hexo new page categories
```

[![image.png](https://i.postimg.cc/VLXgh2Kz/image.png)](https://postimg.cc/ZCK6BskQ)

### 搜索功能

### 加密

<span id="jump_功能补充页">跳转到的地方</span>



----



