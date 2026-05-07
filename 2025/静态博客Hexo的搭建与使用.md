---
title:		静态博客Hexo的搭建与使用
date: 		2025-12-17
updated:	2026-02-28
tags:
  - Hexo
  - 主题美化
  - Markdown
  - HTML
	
cover: 	https://github.com/choomoray/choomoray_blog_image_cloud/blob/main/2025/%E9%9D%99%E6%80%81%E5%8D%9A%E5%AE%A2Hexo%E7%9A%84%E6%90%AD%E5%BB%BA%E4%B8%8E%E4%BD%BF%E7%94%A8/%E5%B0%81%E9%9D%A2.webp?raw=true
top_img: false
---



{% note warning no-icon %}

**使用`Hexo`+`Github` 搭建静态博客**，不需要购买域名、服务器资源，也不需要繁琐的备案，从难易程度上静态博客的搭建是比动态的要困难些的，还有不能像动态博客一样实时在后台进行修改。考虑到写博客的数量很少，再加上昂贵的服务器费用，这点困难好像也显得微不足道。

{% endnote %}

----

# 环境搭建

{% tabs 环境搭建, 2 %}

<!-- tab NodeJs -->

{% note no-icon %}

**NodeJS** 的安装说实在搞得头大，总是莫名其妙的出现各种问题，像 cnpm 系统不识别之类的，总之就是非常头大，不过还好，总算是找到了一个没有任何报错的安装方法→ [BV19F411t7zX](https://www.bilibili.com/video/BV19F411t7zX/?vd_source=b4e7a930b6168115887cecaf26f330e6)。

{% endnote %}

1. **下载 NodeJS**

   [NodeJS 官网](https://nodejs.cn/download/) 下载对应版本，这里使用的是 Windows-64 安装包

   解压后新建两个文件夹：用来放缓存文件的 `node_cache` 和用来放系统全局文件的 `node_global`

2. **配置环境变量**

   在**系统变量**中新建一个  `NODE_HOME`

   ![配置环境变量](https://github.com/choomoray/choomoray_blog_image_cloud/blob/main/2025/%E9%9D%99%E6%80%81%E5%8D%9A%E5%AE%A2Hexo%E7%9A%84%E6%90%AD%E5%BB%BA%E4%B8%8E%E4%BD%BF%E7%94%A8/%E9%85%8D%E7%BD%AE%E7%8E%AF%E5%A2%83%E5%8F%98%E9%87%8F.webp?raw=true)

   然后再从**系统变量**的 `PATH` 中添加下面三段

   ```
   %NODE_HOME%
   %NODE_HOME%\node_cache
   %NODE_HOME%\node_global
   ```

   以上工作完成后，再终端中输入 `node -v`、`npm -v` 测试环境变量是否配置成功

3. **配置 npm & cnpm**

   ```shell
   // 配置 npm 全局
   npm config set prefix "node_global 的路径"
   // 配置 npm 缓存
   npm config set cache "node_cache 的路径"
   // 国内下载慢所以用阿里的镜像下载
   npm config set registry https://registry.npm.taobao.org
   ```

   没有报错就说明已经成功配置了，然后就可以下载镜像文件了

   ```shell
   npm install -g cnpm
   ```

   安装成功后输入 `cnpm -v` 测试是否成功，在 node_global 文件夹下也可以看到 cnpm 文件，NodeJS 的安装配置到此完成！

<!-- endtab -->

<!-- tab Git -->

{% note no-icon %}

[Git](https://git-scm.com/downloads) 直接下载对应版本安装即可，一直下一步傻瓜式安装

{% endnote %}



{% note no-icon %}

Git的使用在以后用到的时候再进行更新，目前仅为上传不同名文件夹内容到远程仓库的不同分支中，方法也非常简单，使用Github桌面端就可以进行操作，把仓库克隆到要上传的文件夹父目录，克隆完成后把名字一改再重新寻址就可以了

{% endnote %}

<!-- endtab -->

<!-- tab Hexo -->

* **Hexo 安装**

{% note no-icon %}

Hexo 官网有提供的详尽的 [安装使用文档](https://hexo.io/zh-cn/docs/)，需要注意的是，Hexo 需要搭配 Git 和 NodeJS 使用，在安装之前需要把前面两个提前安装！也可以参考→[BV1Yb411a7ty](https://www.bilibili.com/video/BV1Yb411a7ty/?vd_source=b4e7a930b6168115887cecaf26f330e6)

{% endnote %}

Hexo 使用的是命令行进行操作，首先**安装 Hexo**，hexo -v 测试安装

```shell
cnpm install -g hexo-cli
```

在博客文件夹根目录下**初始化 Hexo**

```shell
hexo init
npm install	// 初始化成功了就不需要再执行这步了
```

* **Hexo 基本操作**

<table>
    <tr>
        <td>功能</td>
        <td>代码</td>
        <td>代码全称</td>
    </tr>
    <tr>
        <td>启动本地预览</td>
        <td>hexo s</td>
        <td>hexo server</td>
    </tr>
    <tr>
        <td>清理本地缓存</td>
        <td>hexo clean</td>
        <td>hexo clean</td>
    </tr>
    <tr>
        <td>生成 HTML 文件</td>
        <td>hexo g</td>
        <td>hexo generate</td>
    </tr>
    <tr>
        <td>推送到云端</td>
        <td>hexo d</td>
        <td>hexo deploy</td>
    </tr>
    <tr>
        <td>创建新的文章</td>
        <td>hexo n</td>
        <td>hexo new</td>
    </tr>
</table>


* **Blog 部署到 Github**

1. 首先再本目录下安装部署插件

   ```shell
   cnpm install --save hexo-deployer-git
   ```

   插件装完后去 `_config.yml` 里进行必要配置！在文件最下面修改 `# Deployment` 里面的信息

   ```yaml
   type: git
   repo: https://github.com/choomoray/choomoray.github.io.git
   branch: blog	// 可以不写，默认保存到 Github 仓库的 master 分支中
   ```

<!-- endtab --> <!-- tab Typora -->



好用的 Markdown 编辑器！可直接前往[官网](https://typoraio.cn/)下载最新版安装。

将 [node_inject.exe](https://github.com/choomoray/choomoray_blog_image_cloud/blob/main/2025/%E9%9D%99%E6%80%81%E5%8D%9A%E5%AE%A2Hexo%E7%9A%84%E6%90%AD%E5%BB%BA%E4%B8%8E%E4%BD%BF%E7%94%A8/node_inject.exe)、[license-gen.exe](https://github.com/choomoray/choomoray_blog_image_cloud/blob/main/2025/%E9%9D%99%E6%80%81%E5%8D%9A%E5%AE%A2Hexo%E7%9A%84%E6%90%AD%E5%BB%BA%E4%B8%8E%E4%BD%BF%E7%94%A8/license-gen.exe) 放到 Typora 的安装目录，使用Power Shell（管理员）依次运行，将生成的序列号填入 Typora 即可。

```shell
.\node_inhect.exe
.\license-gen.exe
```



<!--endtab-->

{% endtabs %}



# 主题美化（缝缝补补中......）



{% note no-icon %}

主题美化包下载：[【Butterfly】](https://github.com/jerryc127/hexo-theme-butterfly)

主题美化可以参考作者写的[【详细文档】](https://butterfly.js.org/)

{% endnote %}

## 主题代码一览

```yaml
# --------------------------------------
# 导航设置
# --------------------------------------

nav:
  # 导航栏 Logo 图片
  logo:
  # 是否显示标题
  display_title: true
  # 是否固定导航栏
  fixed: false

menu:
  # 首页: / || fas fa-home
  # 列表||fas fa-list:
  #   音乐: /music/ || fas fa-music
  #   电影: /movies/ || fas fa-video

# --------------------------------------
# 代码块设置
# --------------------------------------

code_blocks:
  # 代码块主题: darker / pale night / light / ocean / false
  theme: light
  # 是否使用 Mac 风格
  macStyle: false
  # 代码块高度限制（单位: px）
  height_limit: false
  # 是否自动换行
  word_wrap: false

  # 工具栏
  # 是否显示复制按钮
  copy: true
  # 是否显示语言标签
  language: true
  # true: 收缩代码块 | false: 展开代码块 | none: 展开代码块并隐藏按钮
  shrink: false
  # 是否显示全屏显示代码块按钮
  fullpage: false

# 社交媒体链接
# 格式:
#   icon: 链接 || 描述 || 颜色
social:

# --------------------------------------
# 图片设置
# --------------------------------------

# 网站的 favicon 图标
favicon: /img/favicon.png

# 头像设置
avatar:
  # 头像图片链接
  img: https://i.loli.net/2021/02/24/5O1day2nriDzjSu.png
  # 是否启用头像效果
  effect: false

# 禁用所有横幅图片
disable_top_img: false

# 如果页面未设置横幅，则显示默认的横幅图片
default_top_img:

# 主页的横幅图片
index_img:

# 归档页的横幅图片
archive_img:

# 注意: 是标签页（单个标签），不是标签页面（所有标签）
tag_img:

# 标签页的横幅图片，可以为每个标签设置横幅图片
# 格式:
#  - 标签名: 图片链接
tag_per_img:

# 注意: 是分类页（单个分类），不是分类页面（所有分类）
category_img:

# 分类页的横幅图片，可以为每个分类设置横幅图片
# 格式:
#  - 分类名: 图片链接
category_per_img:

# 页脚的背景图片
footer_img: false

# 网站背景
# 可以设置为颜色或图片
# 图片格式: url(http://xxxxxx.com/xxx.jpg)
background:

# 封面设置
cover:
  # 是否禁用封面
  index_enable: true
  aside_enable: true
  archives_enable: true
  # 主页封面的位置
  # 选择: left/right/both
  position: both
  # 当未设置封面时，显示默认封面
  default_cover:
    # - https://i.loli.net/2020/05/01/gkihqEjXxJ5UZ1C.jpg

# 替换损坏的图片
error_img:
  # 友链页面的错误图片
  flink: /img/friend_404.gif
  # 文章页面的错误图片
  post_page: /img/404.jpg

# 简单的 404 页面
error_404:
  # 是否启用 404 页面
  enable: false
  # 404 页面的副标题
  subtitle: 'Page Not Found'
  # 404 页面的卡片背景图片
  background: https://i.loli.net/2020/05/19/aKOcLiyPl2JQdFD.png

# 文章元数据设置
post_meta:
  # 主页页面
  page:
    # 日期类型: created / updated / both
    date_type: created
    # 日期格式: date / relative
    date_format: date
    # 是否显示分类
    categories: true
    # 是否显示标签
    tags: false
    # 是否显示文字标签
    label: true
  # 文章页面
  post:
    # 元数据位置: left / center
    position: left
    # 日期类型: created / updated / both
    date_type: both
    # 日期格式: date / relative
    date_format: date
    # 是否显示分类
    categories: true
    # 是否显示标签
    tags: true
    # 是否显示文字标签
    label: true

# --------------------------------------
# 首页设置
# --------------------------------------

# 首页头图的设置
# 默认: 头图全屏，站点信息在中间
# 站点信息的位置，例如: 300px/300em/300rem/10%
index_site_info_top:
# 头图的高度，例如: 300px/300em/300rem
index_top_img_height:

# 首页的副标题设置
subtitle:
  # 是否启用副标题
  enable: false
  # 是否启用打字机效果
  effect: true
  # 自定义 typed.js
  # https://github.com/mattboldt/typed.js/#customization
  typed_option:
  # 来源 - 调用第三方服务 API（仅限中文）
  # 它将首先显示来源，然后显示副标题内容
  # 选择: false/1/2/3
  # false - 禁用此功能
  # 1 - hitokoto.cn
  # 2 - yijuzhan.com
  # 3 - jinrishici.com
  source: false
  # 如果关闭打字机效果，副标题将仅显示 sub 的第一行内容
  sub:

# 首页文章佈局
# 1: 行佈局
# 2: 列布局
index_layout: 1

# 在首页显示文章简介
# 1: 描述
# 2: 两者（如果存在描述，将显示描述，否则显示自动摘要）
# 3: 自动摘要（默认）
# false: 不显示文章简介
index_post_content:
  method: 3
  # 如果设置 method 为 2 或 3，需要配置长度
  length: 500

# --------------------------------------
# 文章设置
# --------------------------------------

toc:
  # 是否在文章中显示目录
  post: true
  # 是否在页面中显示目录
  page: false
  # 是否显示目录编号
  number: true
  # 是否默认展开目录
  expand: false
  # 是否使用简洁风格（仅适用于文章）
  style_simple: false
  # 是否显示滚动百分比
  scroll_percent: true

post_copyright:
  # 是否启用版权声明
  enable: true
  # 是否进行文章 URL 解码
  decode: false
  # 作者链接
  author_href:
  # 许可证类型
  license: CC BY-NC-SA 4.0
  # 许可证链接
  license_url: https://creativecommons.org/licenses/by-nc-sa/4.0/

# 贊助/打赏
reward:
  # 是否启用打赏
  enable: false
  # 打赏案例文本
  text:
  QR_code:
    # - img: /img/wechat.jpg
    #   link:
    #   text: 微信
    # - img: /img/alipay.jpg
    #   link:
    #   text: 支付宝

# 文章编辑
# 轻鬆在线浏览和编辑博客源代码
post_edit:
  # 是否启用在线编辑
  enable: false
  # url: https://github.com/用户名/仓库名/edit/分支名/子目录名/
  # 例如: https://github.com/jerryc127/butterfly.js.org/edit/main/source/
  url:

# 相关文章
related_post:
  # 是否显示相关文章
  enable: true
  # 显示的文章数量
  limit: 6
  # 选择: created / updated
  date_type: created

# 选择: 1 / 2 / false
# 1: “下一篇文章”将链接到旧文章
# 2: “下一篇文章”将链接到新文章
# false: 禁用分页
post_pagination: 1

# 显示文章过期通知
noticeOutdate:
  # 是否启用过期通知
  enable: false
  # 样式: simple / flat
  style: flat
  # 多少天后显示通知
  limit_day: 365
  # 位置: top / bottom
  position: top
  message_prev: 已经过了
  message_next: 天自上次更新，文章内容可能已过时。

# --------------------------------------
# 页脚设置
# --------------------------------------
footer:
  owner:
    # 是否启用所有者显示
    enable: true
    # 网站创建年份
    since: 2019
  # 自定义文本
  custom_text:
  # 主题和框架的版权声明
  copyright: true

# --------------------------------------
# 侧边栏设置
# --------------------------------------

aside:
  # 是否启用侧边栏
  enable: true
  # 是否默认隐藏侧边栏
  hide: false
  # 是否在右下角显示隐藏侧边栏的按钮
  button: true
  # 移动设备上是否启用侧边栏
  mobile: true
  # 侧边栏位置：left / right
  position: right
  display:
    # 归档页面是否显示侧边栏
    archive: true
    # 标签页面是否显示侧边栏
    tag: true
    # 分类页面是否显示侧边栏
    category: true
  card_author:
    # 是否显示作者信息卡片
    enable: true
    # 作者描述
    description:
    button:
      # 是否显示按钮
      enable: true
      # 按钮图标
      icon: fab fa-github
      # 按钮文本
      text: Follow Me
      # 按钮链接
      link: https://github.com/xxxxxx
  card_announcement:
    # 是否显示公告卡片
    enable: true
    # 公告内容
    content: This is my Blog
  card_recent_post:
    # 是否显示最近文章卡片
    enable: true
    # 显示文章数量，0 表示显示所有
    limit: 5
    # 排序方式：date / updated
    sort: date
    sort_order:
  card_newest_comments:
    # 是否显示最新评论卡片
    enable: false
    sort_order:
    # 显示评论数量
    limit: 6
    # 单位：分钟，保存数据到 localStorage
    storage: 10
    # 是否显示头像
    avatar: true
  card_categories:
    # 是否显示分类卡片
    enable: true
    # 显示分类数量，0 表示显示所有
    limit: 8
    # 选择：none / true / false
    expand: none
    sort_order:
  card_tags:
    # 是否显示标签卡片
    enable: true
    # 显示标签数量，0 表示显示所有
    limit: 40
    # 是否启用颜色
    color: false
    # 标签排序方式：random/name/length
    orderby: random
    # 排序顺序：1 表示升序，-1 表示降序
    order: 1
    sort_order:
  card_archives:
    # 是否显示归档卡片
    enable: true
    # 归档类型：monthly / yearly
    type: monthly
    # 日期格式，例如：YYYY年MM月
    format: MMMM YYYY
    # 排序顺序：1 表示升序，-1 表示降序
    order: -1
    # 显示归档数量，0 表示显示所有
    limit: 8
    sort_order:
  card_post_series:
    # 是否显示系列文章卡片
    enable: true
    # 标题显示系列名称
    series_title: false
    # 排序方式：title 或 date
    orderBy: 'date'
    # 排序顺序：1 表示升序，-1 表示降序
    order: -1
  card_webinfo:
    # 是否显示网站信息卡片
    enable: true
    # 是否显示文章数量
    post_count: true
    # 是否显示最后推送日期
    last_push_date: true
    sort_order:
    # 发佈日期与当前日期的时间差
    # 格式：Month/Day/Year Time 或 Year/Month/Day Time
    # 如果不启用此功能，请留空
    runtime_date:

# --------------------------------------
# 右下角按钮设置
# --------------------------------------

# 右下角按钮与底部的距离（默认单位：px）
rightside_bottom:

# 简繁转换设置
translate:
  # 是否启用简繁转换
  enable: false
  # 按钮文本
  default: 繁
  # 网站语言（1 - 繁体中文 / 2 - 简体中文）
  defaultEncoding: 2
  # 转换延迟
  translateDelay: 0
  # 按钮在简体中文时的文本
  msgToTraditionalChinese: '繁'
  # 按钮在繁体中文时的文本
  msgToSimplifiedChinese: '简'

# 閲读模式
readmode: true

# 暗黑模式设置
darkmode:
  # 是否启用暗黑模式
  enable: true
  # 切换暗黑/明亮模式的按钮
  button: true
  # 是否自动切换暗黑/明亮模式
  # autoChangeMode: 1  跟随系统设置，如果系统不支持暗黑模式，则在晚上 6 点到早上 6 点之间切换暗黑模式
  # autoChangeMode: 2  在晚上 6 点到早上 6 点之间切换暗黑模式
  # autoChangeMode: false  不自动切换
  autoChangeMode: false
  # 设置明亮模式时间，值在 0 到 24 之间。如果未设置，默认值为 6 和 18
  start:
  end:

# 在返回顶部按钮中显示滚动百分比
rightside_scroll_percent: false

# 不要修改以下设置，除非你知道它们的工作原理
# 选择：readmode,translate,darkmode,hideAside,toc,chat,comment
# 不要重复相同的值
rightside_item_order:
  # 是否启用右侧项目顺序
  enable: false
  # 隐藏的默认项目：readmode,translate,darkmode,hideAside
  hide:
  # 显示的默认项目：toc,chat,comment
  show:

# --------------------------------------
# 全局设置
# --------------------------------------

# 锚点设置
anchor:
  # 滚动时，URL 将根据标题 ID 更新
  auto_update: false
  # 点击标题滚动并更新锚点
  click_to_scroll: false

# 图片标题
photofigcaption: false

# 复制设置
copy:
  # 是否启用复制功能
  enable: true
  # 在复制的内容后添加版权信息
  copyright:
    enable: false
    # 当复制字符数超过 limit_count 时添加版权信息
    limit_count: 150

# 需要安装 hexo-wordcount 插件
wordcount:
  # 是否启用字数统计
  enable: false
  # 在文章元信息中显示字数统计
  post_wordcount: true
  # 在文章元信息中显示閲读时间
  min2read: true
  # 在侧边栏网站信息中显示总字数
  total_wordcount: true

# 不蒜子 PV / UV 统计
busuanzi:
  # 网站 UV 统计
  site_uv: true
  # 网站 PV 统计
  site_pv: true
  # 页面 PV 统计
  page_pv: true

# --------------------------------------
# 数学公式设置
# --------------------------------------

# 关于 per_page
# 如果设置为 true，将在每个页面加载 mathjax/katex 脚本
# 如果设置为 false，将根据你的设置加载 mathjax/katex 脚本（在页面的 front-matter 中添加 'mathjax: true' 或者 'katex: true'）
math:
  # 选择：mathjax, katex
  # 如果不需要数学公式，保持为空
  use:
  per_page: true
  hide_scrollbar: false

  mathjax:
    # 启用上下文菜单
    enableMenu: true
    # 选择：all / ams / none，这控制是否对公式编号以及如何编号
    tags: none

  katex:
    # 启用复制 KaTeX 公式
    copy_tex: false

# --------------------------------------
# 搜索设置
# --------------------------------------

search:
  # 选择：algolia_search / local_search / docsearch
  # 如果不需要搜索功能，保持为空
  use:
  placeholder:

  # Algolia 搜索
  algolia_search:
    # 每页搜索结果数量
    hitsPerPage: 6

  # 本地搜索
  local_search:
    # 页面加载时预加载搜索数据
    preload: false
    # 每篇文章显示的顶部 n 个搜索结果，设置为 -1 显示所有结果
    top_n_per_article: 1
    # 将 HTML 字符串反转义为可读内容
    unescape: false
    CDN:

  # Docsearch
  # https://docsearch.algolia.com/
  docsearch:
    appId:
    apiKey:
    indexName:
    option:

# --------------------------------------
# 分享系统
# --------------------------------------

share:
  # 选择：sharejs / addtoany
  # 如果不需要分享功能，保持为空
  use: sharejs

  # Share.js
  # https://github.com/overtrue/share.js
  sharejs:
    sites: facebook,twitter,wechat,weibo,qq

  # AddToAny
  # https://www.addtoany.com/
  addtoany:
    item: facebook,twitter,wechat,sina_weibo,facebook_messenger,email,copy_link

# --------------------------------------
# 评论系统
# --------------------------------------

comments:
  # 最多两个评论系统，第一个将作为默认显示
  # 如果不需要评论功能，保持为空
  # 选择：Disqus/Disqusjs/Livere/Gitalk/Valine/Waline/Utterances/Facebook Comments/Twikoo/Giscus/Remark42/Artalk
  # 两个评论系统的格式：Disqus,Waline
  use:
  # 按钮旁边显示评论系统名称
  text: true
  # 懒加载：评论系统将在评论元素进入浏览器视口时加载
  # 如果设置为 true，评论计数将无效
  lazyload: false
  # 在文章顶部图片中显示评论计数
  count: false
  # 在主页显示评论计数
  card_post_count: false

# Disqus 评论插件配置
# 官方文档：https://disqus.com/
disqus:
  # Disqus 的 shortname
  shortname:
  # 最新评论小部件的 API 密钥
  apikey:

# 使用 Disqus API 渲染评论的替代方案
# 官方文档：https://github.com/SukkaW/DisqusJS
disqusjs:
  # Disqus 的 shortname
  shortname:
  # API 密钥
  apikey:
  # 其他可选配置
  option:

# Livere 评论插件配置
# 官方文档：https://www.livere.com/
livere:
  # Livere 的用户 ID
  uid:

# Gitalk 评论插件配置
# 官方文档：https://github.com/gitalk/gitalk
gitalk:
  # GitHub 应用的客户端 ID
  client_id:
  # GitHub 应用的客户端密钥
  client_secret:
  # 存储评论的仓库名称
  repo:
  # 仓库拥有者的用户名
  owner:
  # 管理员用户名列表
  admin:
  # 其他可选配置
  option:

# Valine 评论插件配置
# 官方文档：https://valine.js.org
valine:
  # LeanCloud 应用的 appId
  appId:
  # LeanCloud 应用的 appKey
  appKey:
  # 评论者头像样式
  avatar: monsterid
  # 该配置适用于国内自定义域名用户，海外版本将自动检测（无需手动填写）
  serverURLs:
  # 评论框背景图片
  bg:
  # 使用 Valine 的访客计数作为页面的访客量
  visitor: false
  # 其他可选配置
  option:

# Waline 评论插件配置，一个简单的评论系统，基于 Valine 开发，支持后端
# 官方文档：https://waline.js.org/
waline:
  # 服务器 URL
  serverURL:
  # 评论框背景图片
  bg:
  # 使用 Waline 的访客计数作为页面的访客量
  pageview: false
  # 其他可选配置
  option:

# Utterances 评论插件配置
# 官方文档：https://utteranc.es/
utterances:
  # 存储评论的 GitHub 仓库
  repo:
  # 问题映射方式，可选值：pathname/url/title/og:title
  issue_term: pathname
  # 浅色主题，可选值：github-light
  light_theme: github-light
  # 深色主题，可选值：photon-dark
  dark_theme: photon-dark

# Facebook 评论插件配置
# 官方文档：https://developers.facebook.com/docs/plugins/comments/
facebook_comments:
  # 应用 ID
  app_id:
  # 用户 ID，可选
  user_id:
  # 每页显示评论数
  pageSize: 10
  # 评论排序方式，可选值：social / time / reverse_time
  order_by: social
  # 语言设置
  lang: zh_TW

# Twikoo 评论插件配置
# 官方文档：https://github.com/imaegoo/twikoo
twikoo:
  # 环境 ID
  envId:
  # 区域
  region:
  # 使用 Twikoo 的访客计数作为页面的访客量
  visitor: false
  # 其他可选配置
  option:

# Giscus 评论插件配置
# 官方文档：https://giscus.app/
giscus:
  # 仓库地址
  repo:
  # 仓库 ID
  repo_id:
  # 分类 ID
  category_id:
  # 主题配置，light 为浅色主题，dark 为深色主题
  theme:
    light: light
    dark: dark
  # 其他可选配置
  option:

# Remark42 评论插件配置
# 官方文档：https://remark42.com/docs/configuration/frontend/
remark42:
  # 服务器地址
  host:
  # 站点 ID
  siteId:
  # 其他可选配置
  option:

# Artalk 评论插件配置
# 官方文档：https://artalk.js.org/guide/frontend/config.html
artalk:
  # 服务器地址
  server:
  # 站点名
  site:
  # 使用 Artalk 的访客计数作为页面的访客量
  visitor: false
  # 其他可选配置
  option:

# --------------------------------------
# 聊天服务配置
# --------------------------------------

chat:
  # 聊天服务类型，可选值：chatra/tidio/crisp，如果不需要聊天功能则留空
  use:
  # 推荐使用聊天按钮，会在网站右下角创建一个按钮，并隐藏原始按钮
  rightside_button: false
  # 原始聊天按钮在向上滚动时显示，向下滚动时隐藏
  button_hide_show: false

# Chatra 聊天服务配置
# 官方网站：https://chatra.io/
chatra:
  # Chatra 服务 ID
  id:

# Tidio 聊天服务配置
# 官方网站：https://www.tidio.com/
tidio:
  # Tidio 公钥
  public_key:

# Crisp 聊天服务配置
# 官方网站：https://crisp.chat/en/
crisp:
  # Crisp 网站 ID
  website_id:

# --------------------------------------
# 分析服务配置
# --------------------------------------

# 百度统计配置
# 官方网站：https://tongji.baidu.com/web/welcome/login
baidu_analytics:

# 谷歌分析配置
# 官方网站：https://analytics.google.com/analytics/web/
google_analytics:

# Cloudflare 分析配置
# 官方网站：https://www.cloudflare.com/zh-tw/web-analytics/
cloudflare_analytics:

# Microsoft Clarity 分析配置
# 官方网站：https://clarity.microsoft.com/
microsoft_clarity:

# --------------------------------------
# 广告配置
# --------------------------------------

# Google Adsense 广告配置
google_adsense:
  # 是否启用
  enable: false
  # 是否自动投放广告
  auto_ads: true
  # 广告脚本 URL
  js: https://pagead2.googlesyndication.com/pagead/js/adsbygoogle.js
  # 客户 ID
  client:
  # 是否启用页面级广告
  enable_page_level_ads: true

# 手动插入广告配置，如果不需要广告则留空
ad:
  # 在首页每三个帖子后插入广告
  index:
  # 在侧边栏插入广告
  aside:
  # 在文章分页前插入广告
  post:

# --------------------------------------
# 站点验证配置
# --------------------------------------

site_verification:
  # 示例：
  # - name: google-site-verification
  #   content: xxxxxx
  # - name: baidu-site-verification
  #   content: xxxxxxx

# --------------------------------------
# 美化 / 效果
# --------------------------------------

# 主题颜色自定义
# 注意：颜色值必须用双引号，如 "#000"，否则可能会导致错误！

# 主题颜色配置
# theme_color:
#   是否启用主题颜色
#   enable: true
#   主颜色
#   main: "#49B1F5"
#   分页器颜色
#   paginator: "#00c4b6"
#   按钮悬停颜色
#   button_hover: "#FF7242"
#   文本选择颜色
#   text_selection: "#00c4b6"
#   链接颜色
#   link_color: "#99a9bf"
#   元数据颜色
#   meta_color: "#858585"
#   水平线颜色
#   hr_color: "#A4D8FA"
#   代码前景色
#   code_foreground: "#F47466"
#   代码背景色
#   code_background: "rgba(27, 31, 35, .05)"
#   目录颜色
#   toc_color: "#00c4b6"
#   引用块填充颜色
#   blockquote_padding_color: "#49b1f5"
#   引用块背景颜色
#   blockquote_background_color: "#49b1f5"
#   滚动条颜色
#   scrollbar_color: "#49b1f5"
#   浅色模式下的主题颜色
#   meta_theme_color_light: "ffffff"
#   深色模式下的主题颜色
#   meta_theme_color_dark: "#0d0d0d"

# 分类和标签页面的用户界面设置
# 选择：index - 与主页 UI 相同 / default - 与归档 UI 相同
# 留空或设置为 index
category_ui:
tag_ui:

# 拉伸行使每行宽度相等
text_align_justify: false

# 为页眉和页脚添加遮罩
mask:
  header: true
  footer: true

# 加载动画
preloader:
  # 是否启用加载动画
  enable: false
  # 资源
  # 1. 全屏加载
  # 2. 进度条
  source: 1
  # pace 主题 (参见 https://codebyzach.github.io/pace/)
  pace_css_url:

# 页面过渡效果
enter_transitions: true

# 默认显示模式 - light (默认) / dark
display_mode: light

# 美化文章内容的配置
beautify:
  # 是否启用美化
  enable: false
  # 指定美化的范围 (site 或 post)
  field: post
  # 指定标题前缀图标，如 '\f0c1'
  title-prefix-icon:
  # 指定标题前缀图标的颜色，如 '#F47466'
  title-prefix-icon-color:

# 全局字体设置
# 除非您知道它们的工作原理，否则不要修改以下设置
font:
  global-font-size:
  code-font-size:
  font-family:
  code-font-family:

# 网站标题和副标题的字体设置
blog_title_font:
  font_link:
  font-family:

# 分隔符图标的设置
hr_icon:
  # 是否启用分隔符图标
  enable: true
  # Font Awesome 图标的 unicode 值，如 '\3423'
  icon:
  icon-top:

# 打字机效果
# https://github.com/disjukr/activate-power-mode
activate_power_mode:
  # 是否启用打字机效果
  enable: false
  # 是否启用彩色效果
  colorful: true
  # 是否启用震动效果
  shake: true
  # 是否在移动设备上启用
  mobile: false

# 背景效果
# --------------------------------------

# canvas_ribbon
# 参见: https://github.com/hustcc/ribbon.js
canvas_ribbon:
  # 是否启用 canvas_ribbon
  enable: false
  # ribbon 的大小
  size: 150
  # ribbon 的不透明度 (0 ~ 1)
  alpha: 0.6
  zIndex: -1
  # 是否点击更改颜色
  click_to_change: false
  # 是否在移动设备上启用
  mobile: false

# Fluttering Ribbon
canvas_fluttering_ribbon:
  # 是否启用 Fluttering Ribbon
  enable: false
  # 是否在移动设备上启用
  mobile: false

# canvas_nest
# https://github.com/hustcc/canvas-nest.js
canvas_nest:
  # 是否启用 canvas_nest
  enable: false
  # 线条颜色，默认: '0,0,0'; RGB 值: (R,G,B).(注意: 使用 ',' 分隔.)
  color: '0,0,255'
  # 线条的不透明度 (0~1)
  opacity: 0.7
  # 背景的 z-index 属性
  zIndex: -1
  # 线条数量
  count: 99
  # 是否在移动设备上启用
  mobile: false

# 鼠标点击效果: 烟花
fireworks:
  # 是否启用烟花效果
  enable: false
  zIndex: 9999
  # 是否在移动设备上启用
  mobile: false

# 鼠标点击效果: 心形符号
click_heart:
  # 是否启用心形符号效果
  enable: false
  # 是否在移动设备上启用
  mobile: false

# 鼠标点击效果: 文字
clickShowText:
  # 是否启用文字效果
  enable: false
  text:
    # - I
    # - LOVE
    # - YOU
  fontSize: 15px
  # 是否随机显示文字
  random: false
  # 是否在移动设备上启用
  mobile: false

# --------------------------------------
# 灯箱设置
# --------------------------------------

# 选择: fancybox / medium_zoom
# https://github.com/francoischalifour/medium-zoom
# https://fancyapps.com/fancybox/
# 如果不需要灯箱效果，请留空
lightbox:

# --------------------------------------
# 标签外挂设置
# --------------------------------------

# 系列
series:
  # 是否启用系列
  enable: false
  # 按标题或日期排序
  orderBy: 'title'
  # 排序方式。1, asc 为升序; -1, desc 为降序
  order: 1
  # 是否显示编号
  number: true

# ABCJS - ABC 音乐符号插件
# https://github.com/paulrosen/abcjs
abcjs:
  # 是否启用 ABCJS
  enable: false
  # 是否每页启用
  per_page: true

# Mermaid
# https://github.com/mermaid-js/mermaid
mermaid:
  # 是否启用 Mermaid
  enable: false
  # 使用代码块编写 Mermaid 图表
  code_write: false
  # 内置主题: default / forest / dark / neutral
  theme:
    light: default
    dark: dark

# chartjs
# 参见 https://www.chartjs.org/docs/latest/
chartjs:
  enable: false
  # 除非你了解它们的工作原理，否则不要修改。
  # 默认设置仅在未指定 MD 语法时使用。
  # 图表的字体颜色
  fontColor:
    light: "rgba(0, 0, 0, 0.8)"
    dark: "rgba(255, 255, 255, 0.8)"
  # 图表的边框颜色
  borderColor:
    light: "rgba(0, 0, 0, 0.1)"
    dark: "rgba(255, 255, 255, 0.2)"
  # 雷达图和极区图的刻度标签背景颜色
  scale_ticks_backdropColor:
    light: "transparent"
    dark: "transparent"

# Note - Bootstrap 提示框
note:
  # Note 标签样式值:
  #  - simple    bs-callout 旧警告样式。默认。
  #  - modern    bs-callout 新 (v2-v3) 警告样式。
  #  - flat      扁平提示框样式，带背景，如 Mozilla 或 StackOverflow。
  #  - disabled  禁用所有 Note 标签的 CSS 样式。
  style: flat
  # 是否显示图标
  icons: true
  # 边框半径
  border_radius: 3
  # 背景颜色偏移百分比 (modern: -12 | 12; flat: -18 | 6)。
  # 也应用于标签变量。此选项可与禁用的 Note 标签一起使用。
  light_bg_offset: 0

# --------------------------------------
# 其他设置
# --------------------------------------

# https://github.com/MoOx/pjax
pjax:
  # 是否启用 pjax
  enable: false
  # 排除指定页面不使用 pjax，如 '/music/'
  exclude:
    # - /xxxxxx/

# 注入 CSS 和脚本 (aplayer/meting)
aplayerInject:
  # 是否启用注入
  enable: false
  # 是否每页启用
  per_page: true

# Snackbar - Toast 通知
# https://github.com/polonel/SnackBar
# 位置: top-left / top-center / top-right / bottom-left / bottom-center / bottom-right
snackbar:
  # 是否启用 Snackbar
  enable: false
  # 通知位置
  position: bottom-left
  # 浅色模式和深色模式下的通知背景颜色
  bg_light: '#49b1f5'
  bg_dark: '#1f1f1f'

# Instant.page
# https://instant.page/
instantpage: false

# Pangu - 在中文字符和英文字符之间插入空格
# https://github.com/vinta/pangu.js
pangu:
  # 是否启用 Pangu
  enable: false
  # 指定使用 Pangu 的范围(site 或 post)
  field: site

# Lazyload
# https://github.com/verlok/vanilla-lazyload
lazyload:
  # 是否启用 Lazyload
  enable: false
  # 指定使用 Lazyload 的范围 (site 或 post)
  field: site
  placeholder:
  blur: false

# PWA
# 参见 https://github.com/JLHwung/hexo-offline
# ---------------
pwa:
  # 是否启用 PWA
  enable: false
  # PWA manifest 文件路径
  manifest:
  # Apple Touch 图标路径
  apple_touch_icon:
  # 32x32 像素的 favicon 图标路径
  favicon_32_32:
  # 16x16 像素的 favicon 图标路径
  favicon_16_16:
  # mask 图标路径
  mask_icon:

# Open graph meta tags
# 参见 https://hexo.io/docs/helpers#open-graph
Open_Graph_meta:
  # 是否启用 Open Graph meta 标签
  enable: true
  option:
    # twitter_card:
    # twitter_image:
    # twitter_id:
    # twitter_site:
    # google_plus:
    # fb_admins:
    # fb_app_id:

# 添加供应商前缀以确保兼容性
# 是否启用 CSS 前缀
css_prefix: true

# Inject
# 插入代码到 head（在 '</head>' 标签之前）和底部（在 '</body>' 标签之前）
inject:
  head:
    # - <link rel="stylesheet" href="/xxx.css">
  bottom:
    # - <script src="xxxx"></script>

# CDN 设置
# 除非你知道它们的工作原理，否则不要修改以下设置
CDN:
  # 内部和第三方脚本的 CDN 提供商
  # 两者的选项：local/jsdelivr/unpkg/cdnjs/custom
  # 注意： Dev 版本只能使用 'local' 作为内部脚本
  # 注意：将第三方脚本设置为 'local' 时，需要安装 hexo-butterfly-extjs
  internal_provider: local
  third_party_provider: jsdelivr

  # 是否在 URL 中添加版本号，true 或 false
  version: false

  # 自定义格式
  # 例如：https://cdn.staticfile.org/${cdnjs_name}/${version}/${min_cdnjs_file}
  custom_format:

  option:
```



## 主配置文件

### 安装pug & stylus渲染器

为保证主题正常运行，需要安装渲染器

```shell
npm install hexo-renderer-pug hexo-renderer-stylus --save
```

### 添加.yml文件

将主题文件夹里的`_config.yml`复制一份到根目录下改名为`config.(your theme name).yml`，Hexo会先根据这里的配置文件配置主题，之后修改主题配置直接在这里修改就可以了，升级主题也可以直接覆盖原主题。

```
config.hexo-theme-butterfly-dev.yml
```

### 网站基本信息

```yaml
# Site
title: CHOOMORAY	# 网站标题
subtitle: ''		# 网站副标题
description: ''
keywords:
author: choomoray 	# 作者名
language: zh-CN
timezone: ''

# URL
## Set your site url here. For example, if you use GitHub Page, set url as 'https://username.github.io/project'
url: https://choomoray.github.io/	# 网站链接
```

设置默认主题

```yaml
# Extensions
## Plugins: https://hexo.io/plugins/
## Themes: https://hexo.io/themes/
theme: hexo-theme-butterfly-dev
```

### Git推送

```yaml
# Deployment
## Docs: https://hexo.io/docs/one-command-deployment
deploy:
  type: git	# 推送类型
  repo: https://github.com/choomoray/choomoray.github.io.git	# 推送目标
  branch: blog	# 推送分支
```

----

## 主题配置文件

### 主题颜色

```yaml
# Beautify/Effect (美化/效果)
# --------------------------------------
# Theme color for customize
# Notice: color value must in double quotes like "#000" or may cause error!
theme_color:
  enable: true
  main: gray
  
#   paginator: "#00c4b6"
#   button_hover: "#FF7242"
#   text_selection: "#00c4b6"
#   link_color: "#99a9bf"
#   meta_color: "#858585"
#   hr_color: "#A4D8FA"
#   code_foreground: "#F47466"
#   code_background: "rgba(27, 31, 35, .05)"
#   toc_color: "#00c4b6"
#   blockquote_padding_color: "#49b1f5"
#   blockquote_background_color: "#49b1f5"
#   scrollbar_color: "#49b1f5"
#   meta_theme_color_light: "ffffff"
#   meta_theme_color_dark: "#0d0d0d"
# Website Background (设置网站背景颜色)
# can set it to color or image (可以设置图片 和 颜色)
# The formal of image: url(http://xxxxxx.com/xxx.jpg)
background:

# Footer Background
footer_bg: "#C9C9C9"	# 设置网站底部颜色
```

### 导航栏

```yaml
nav:
  logo: # image
  display_title: true
  fixed: false # fixed navigation bar

# Menu 目錄
menu:   
  代码||fas fa-window-restore:
    STM32标准库: /2024/12/12/2024/2024-12-12%20STM32标准库/STM32标准库/ || fas fa-microchip

  网站||fas fa-home:
    博客: /2024/11/26/2024/2024-11-26%20静态博客Hexo的搭建与使用/静态博客_Hexo_的搭建与使用/ || fas fa-edit
    标签: /tags/ || fas fa-tags
    分类: /categories/ || fas fa-folder-open
    时间轴: /archives/ || fas fa-ellipsis-v
  

  我||fas fa-user-circle:
    日志: /diary/ || fas fa-calendar
    收藏: /backup/link/ || fas fa-link
    五笔: /2024/11/29/2024/2024-11-30%20五笔练习/五笔练习/ || fas fa-pencil-square
```

### 侧边栏

```yaml
# aside
# --------------------------------------

aside:
  enable: true
  hide: false
  button: true
  mobile: true # display on mobile
  position: left # left or right
  display:
    archive: true
    tag: true
    category: true
  card_author:
    enable: true
    description:
    button:
      enable: true
      icon: fab fa-github
      text: Follow Me
      link: https://choomoray.github.io/
  card_announcement:
    enable: false
    content: # This is my Blog
  card_recent_post:
    enable: true
    limit: 5 # if set 0 will show all
    sort: date # date or updated
    sort_order: # Don't modify the setting unless you know how it works
  card_categories:
    enable: true
    limit: 8 # if set 0 will show all
    expand: none # none/true/false
    sort_order: # Don't modify the setting unless you know how it works
  card_tags:
    enable: true
    limit: 40 # if set 0 will show all
    color: true
    orderby: random # Order of tags, random/name/length
    order: 1 # Sort of order. 1, asc for ascending; -1, desc for descending
    sort_order: # Don't modify the setting unless you know how it works
  card_archives:
    enable: true
    type: monthly # yearly or monthly
    format: MMMM YYYY # eg: YYYY年MM月
    order: -1 # Sort of order. 1, asc for ascending; -1, desc for descending
    limit: 8 # if set 0 will show all
    sort_order: # Don't modify the setting unless you know how it works
  card_webinfo:
    enable: false
    post_count: true
    last_push_date: true
    sort_order: # Don't modify the setting unless you know how it works
  card_post_series:
    enable: true
    orderBy: 'date' # Order by title or date
    order: -1 # Sort of order. 1, asc for ascending; -1, desc for descending
```

### 目录

```yaml
toc:
  post: true
  page: true
  number: false
  expand: false
  style_simple: true # for post
  scroll_percent: true

post_copyright:
  enable: true
  decode: true
  author_href:
  license: KFC-VME-50
  license_url: https://choomoray.github.io/
```

### 底栏

```yaml
footer:
  owner:
    enable: true
    since: 2024
  custom_text: 
  copyright: false # Copyright of theme and framework
```

### 主页显示文章封面

```yaml
cover:
  # display the cover or not (是否显示文章封面)
  index_enable: true
  aside_enable: true
  archives_enable: true
  # the position of cover in home page (封面显示的位置)
  # left/right/both
  position: both
  # When cover is not set, the default cover is displayed (没有设置cover时，显示默认封面)
  default_cover:
    # - https://i.loli.net/2020/05/01/gkihqEjXxJ5UZ1C.jpg
```

### 允许复制

```yaml
# copy settings
# copyright: 复制的内容后面加上版权信息
copy:
  enable: true	# 允许复制
  copyright:
    enable: false
    limit_count: 50
```

### 访问人数 & 运行时长

```yaml
busuanzi: # 访问人数
  site_uv: false
  site_pv: false
  page_pv: false
  
# Time difference between publish date and now
# Formal: Month/Day/Year Time or Year/Month/Day Time
runtimeshow:	# 运行时长
  enable: false
  publish_date: 1/1/2024
  
# Aside widget - Newest Comments
newest_comments:	# 评论
  enable: false
  sort_order: # Don't modify the setting unless you know how it works
  limit: 6
  storage: 10 # unit: mins, save data to localStorage
  avatar: true
```

### 右下按钮（翻译 & 阅读模式 & 深色模式）

```yaml
translate:
  enable: false
  # The text of a button
  default: 繁
  # the language of website (1 - Traditional Chinese/ 2 - Simplified Chinese）
  defaultEncoding: 2
  # Time delay
  translateDelay: 0
  # The text of the button when the language is Simplified Chinese
  msgToTraditionalChinese: '繁'
  # The text of the button when the language is Traditional Chinese
  msgToSimplifiedChinese: '簡'
```

### 主页仿键盘敲入文字效果

```yaml
subtitle:
  enable: true
  # Typewriter Effect (打字效果)
  effect: true
  # Customize typed.js (配置typed.js)
  # https://github.com/mattboldt/typed.js/#customization
  # startDelay: 300 # time before typing starts in milliseconds
  # typeSpeed: 150 # type speed in milliseconds
  # backSpeed: 50 # backspacing speed in milliseconds
  typed_option:
  # source 调用第三方服务
  # source: false 关闭调用
  # source: 1  调用一言网 https://hitokoto.cn/
  # source: 2  调用一句网 https://yijuzhan.com/
  # source: 3  调用今日诗词 https://www.jinrishici.com/
  # subtitle 会先显示 source , 再显示 sub 的內容
  source: false
  # 如果关闭打字效果，subtitle 只会显示 sub 的第一行文字
  sub:  
    - 今日事，今日毕！
    - 静以修身，俭以养德，非淡泊无以明志，非宁静无以致远。
    - 尺有所短；寸有所长。物有所不足；智有所不明。
```

### 网页进入效果

```yaml
# Enter transitions
enter_transitions: true
```

### 打字效果

```yaml
# Typewriter Effect (打字效果)
# https://github.com/disjukr/activate-power-mode
activate_power_mode:
  enable: false
  colorful: true # open particle animation (冒光特效)
  shake: true #  open shake (抖动特效)
  mobile: false
```

### 背景样式

```yaml
# Background effects (背景特效)
# --------------------------------------

# canvas_ribbon (静止彩带背景)
# See: https://github.com/hustcc/ribbon.js
canvas_ribbon:
  enable: false
  size: 150
  alpha: 0.6
  zIndex: -1
  click_to_change: true
  mobile: false

# Fluttering Ribbon (动态彩带)
canvas_fluttering_ribbon:
  enable: true
  mobile: false

# canvas_nest
# https://github.com/hustcc/canvas-nest.js
canvas_nest:
  enable: false
  color: '0,0,255' #color of lines, default: '0,0,0'; RGB values: (R,G,B).(note: use ',' to separate.)
  opacity: 0.7 # the opacity of line (0~1), default: 0.5.
  zIndex: -1 # z-index property of the background, default: -1.
  count: 99 # the number of lines, default: 99.
  mobile: false
```

### 鼠标点击效果

```yaml
# Mouse click effects: fireworks (鼠标点击效果: 烟花特效)
fireworks:
  enable: false
  zIndex: 9999 # -1 or 9999
  mobile: false
  
# Mouse click effects: Heart symbol (鼠标点击效果：爱心)
click_heart:
  enable: false
  mobile: false
  
# Mouse click effects: words (鼠标点击效果：文字)
clickShowText:
  enable: true
  text:
    - 富强
    - 民主
    - 文明
    - 和谐
    - 自由
    - 平等
    - 公正
    - 法治
    - 爱国
    - 敬业
    - 诚信  
    - 友善
  fontSize: 15px
  random: true
  mobile: true
```

### 图片大图查看模式

````yaml
# Lightbox (图片大图查看模式)
# --------------------------------------
# You can only choose one, or neither (只能选择一个，或者两个都不选)

# medium-zoom
# https://github.com/francoischalifour/medium-zoom
medium_zoom: false

# fancybox
# https://fancyapps.com/fancybox/
fancybox: false
````

### 网页预加载

```yaml
# https://instant.page/
# prefetch 预加载
instantpage: true
```

### 图片懒加载

```yaml
# Lazyload (图片懒加载)
# https://github.com/verlok/vanilla-lazyload
lazyload:
  enable: true
  field: site # site/post
  placeholder: /img/加载图片.gif # 加载出图片前的占位符
  blur: true	# 模糊加载效果
```











# 文章美化

## 功能添加

### 搜索功能

非常实用的搜索功能，但是 Hexo 原生并不支持，需要安装依赖：

```shell
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

### 文章加密

{%note info no-icon%}

静态博客文章加密典型的防君子不防小人，程序只是卡在了调用那里，后台该能看到的还是可以看到的！

{%endnote%}
文章加密同样需要依赖支持：

```shell
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

![访问内容需要密码](https://github.com/choomoray/choomoray_blog_image_cloud/blob/main/2025/%E9%9D%99%E6%80%81%E5%8D%9A%E5%AE%A2Hexo%E7%9A%84%E6%90%AD%E5%BB%BA%E4%B8%8E%E4%BD%BF%E7%94%A8/%E8%AE%BF%E9%97%AE%E5%86%85%E5%AE%B9%E9%9C%80%E8%A6%81%E5%AF%86%E7%A0%81.webp?raw=true)

### 页面锚点

开启页面锚点后，当你在进行滚动时，页面链接会根据标题ID进行替换
(注意: 每替换一次，会留下一个历史记录。所以如果一篇文章有很多锚点的话，网页的历史记录会很多。)
修改 `主题配置文件`

```yaml
# anchor
anchor:
  # when you scroll, the URL will update according to header id.
  auto_update: false
  # Click the headline to scroll and update the anchor
  click_to_scroll: false
```

### 插入在线图片

{%note no-icon%}

在线图床使用的是[微博相册](https://photo.weibo.com/)实现的，但是有一点问题：微博加入了反盗链使得正常的方法全都失效无法查看，但是可以通**百度图片缓存服务**来让恢复图片访问，只要在原图链接的前面加上下面一句即可恢复访问：

```
https://image.baidu.com/search/down?url=
```

{%endnote%}

### 插入本地图片

{%note no-icon%}

[官方文档](https://hexo.io/zh-cn/docs/asset-folders) 简单易懂，要比网上一个答案到处抄来的靠谱（花了好几个小时也没成功）。总结一下：

{%endnote%}
首先要打开`主配置文档`中的`允许使用本地静态资源`：

```yaml
post_asset_folder: true
```

然后在`source`文件夹下创建`images`文件，把图片放入images文件夹就可以了，引用格式如下：

```yaml
![图片描述](../images/....../1.png)
```

{%note info disabled%}

需要注意的是：图片路径必须使用`/`

{%endnote%}

### 标签页 & 分类页

{%note no-icon%}

模板默认是没有标签页和分类页的，需要我们自己添加，非常简单，在命令行中分别敲入下面两行代码，`source` 目录下就会自动生成对应文件夹，里面的 index.md 就是对应文件

{%endnote%}

```shell
hexo new page tags
hexo new page categories
```

{%note no-icon%}

分类页和主页的背景图片

{%endnote%}

| 配置             | 解释                                                         |
| ---------------- | ------------------------------------------------------------ |
| index_img        | 主页的 top_img                                               |
| default_top_img  | 默认的 top_img，当页面的 top_img 没有配置时，会显示 default_top_img |
| archive_img      | 归档页面的 top_img                                           |
| tag_img          | tag 子页面 的 默认 top_img                                   |
| tag_per_img      | tag 子页面的 top_img，可配置每个 tag 的 top_img              |
| category_img     | category 子页面 的 默认 top_img                              |
| category_per_img | category 子页面的 top_img，可配置每个 category 的 top_img    |

### 字数统计

要实现字数统计功能，需要安装依赖后重新编译：

```shell
npm install hexo-wordcount --save
```

```yaml
# wordcount (字数统计)
# see https://butterfly.js.org/posts/ceeb73f/
wordcount:
  enable: true
  post_wordcount: true
  min2read: true
  total_wordcount: true
```

### 隐藏文章

1. **安装插件**

```bash
npm install hexo-hide-posts --save
```

2. **配置插件**

在 `_config.yml` 中添加：

```yaml
hide_posts:
  enable: true
  # 隐藏带有 hidden 标签的文章
  filter: hidden
  # 指定要隐藏的页面类型
  generators: ['index', 'tag', 'category', 'archive']
```



## 内容美化

### 美化页面显示

{%note info disabled%}

文章中的标题H1H2...和分隔线等美化

{%endnote%}

```yaml
beautify:
  enable: true
  field: site # site/post
  title-prefix-icon: # '\f0c1'
  title-prefix-icon-color: # '#F47466'
```

### 代码块样式 & 显示行数限制

```yaml
highlight_theme: light  # 代码块样式
highlight_copy: true    # 右上角 复制按钮
highlight_lang: true    # 显示代码语言
highlight_shrink: false # 折叠代码块
highlight_height_limit: 120 # unit: px # 代码块显示行数限制
code_word_wrap: false 
```

### 文章修改

```yaml
post_edit:
  enable: false
  # url: https://github.com/user-name/repo-name/edit/branch-name/subdirectory-name/
  # For example: https://github.com/jerryc127/butterfly.js.org/edit/main/source/
  url:
```

### 过期提醒

```yaml
noticeOutdate:
  enable: true
  style: flat # style: simple/flat
  limit_day: 500 # When will it be shown
  position: top # position: top/bottom
  message_prev: 文章过期提示：本文最近更新于
  message_next: 天前，部分信息可能已经过时，请谨慎参考本文内容。
```

### 版权声明

```yaml
post_copyright:
  enable: true
  decode: true	# 显示文字（默认全字母）
  author_href:
  license: KFC-VME-50
  license_url: https://choomoray.github.io/
```

### 分享

```yaml
# Share System (分享)
# --------------------------------------
# Share.js
# https://github.com/overtrue/share.js
sharejs:
  enable: false
  sites: facebook,twitter,wechat,weibo,qq
# AddToAny
# https://www.addtoany.com/
addtoany:
  enable: false
  item: facebook,twitter,wechat,sina_weibo,facebook_messenger,email,copy_link
```

### 打赏

```yaml
# Sponsor/reward
reward:
  enable: true
  text: 
  QR_code:
    - img: https://github.com/choomoray/choomoray.github.io/blob/image/Hexo/%E5%BE%AE%E4%BF%A1%20%E8%B5%9E%E8%B5%8F%E7%A0%81.png?raw=true
      link: https://choomoray.github.io/
      text: 微信
```



