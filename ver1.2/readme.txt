
<<ver1.1(共通項目)>>
・使用するソースコード
Kscripter.c          ...main関数
initialize.c         ...画面をクリアにするための関数
Load_first_display.c ...スタート画面を表示させる関数
b_log.c              ...バックログを表示する関数
save.c               ...データをセーブする関数
dis_pause.c          ...一時停止画面を出力するための関数
write_text.c         ...本文を画面に出力するための関数
select_opt.c         ...<SELECT>と<SELECT_END>を読み込んだ時の処理が描かれている
case_binary.c        ...
function.h

・特殊のヘッダファイル
ncurses.h ...TUIを作るためのライブラリ。インストール必須なのでincludeファイルに準備
unistd.h  ...主にsleepを使用する(?)
locale.h  ...

・セーブの仕様

・操作方法

<<ver1.2>>
改善したいところ、確認したいところ
・メニュー画面を指定のものにする
・テキストの囲いを作る
・真ん中にキャラが出てくるようにする
・関数がどのヘッダファイルにあるか(refresh(),)

追加点
・列挙型FLAGの追加(function.h)
・

