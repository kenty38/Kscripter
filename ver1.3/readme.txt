
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
(途中から読み込むようになり原因が分からないため放置)
改善したいところ、確認したいところ
・メニュー画面を指定のものにする
・テキストの囲いを作る
・真ん中にキャラが出てくるようにする
・関数がどのヘッダファイルにあるか(refresh(),)
・case_flagがグローバル関数になっていること
・select_optとcase_binaryの引数が多い

追加点
・列挙型FLAGの追加(function.h)
・

<<ver1.3>>
・現在のスクリプトを記述するwrite_nowlog関数の追加
・b_log.cの中で新たに関数を生成
・save.cの中に新たに関数を生成
・dis_pause.cの中に新たに関数を生成
・strcmpの判定値SAME(=0)を定義
・select_optとcase_binaryが反応した時の返り値REACTを定義
