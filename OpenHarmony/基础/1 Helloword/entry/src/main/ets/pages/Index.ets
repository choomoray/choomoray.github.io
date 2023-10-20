@Entry
@Component
struct TextDemo {
  build() {
    Row() {
      Column() {
        Text('HarmonyOS')
        Text('HarmonyOS')
          .fontColor(Color.Pink)
          .fontSize(20)
          .fontStyle(FontStyle.Italic)
          .fontWeight(FontWeight.Bold)
          .fontFamily('Arial')
      }
      .width('100%')
    }
    .backgroundColor(0xF1F3F5)
    .height('100%')
  }
}