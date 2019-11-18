
<<ver1.1(共通項目)>>
・使用するソースコード
Kscripter.c          ...main関数
initialize.c         ...*画面をクリアにするための関数
Load_first_display.c ...*スタート画面を表示させる関数
b_log.c              ...*バックログを表示する関数
save.c               ...データをセーブする関数
dis_pause.c          ...*一時停止画面を出力するための関数
write_text.c         ...*本文を画面に出力するための関数
select_opt.c         ...*<SELECT>と<SELECT_END>を読み込んだ時の処理が描かれている
case_binary.c        ...選択肢によって分岐させる関数。選択肢を選ぶときはmain.cではなく
                        こちらの関数内のgetchが反応しているため注意。(フラグ管理が複雑)
function.h

・特殊なヘッダファイル
ncurses.h ...TUIを作るためのライブラリ。インストール必須なのでincludeファイルに準備
unistd.h  ...主にsleepを使用する(?)
locale.h  ...

・セーブの仕様
ftellやfseekの仕様確認

・操作方法
画面の下にどのコマンドでどのようになるか記述しておく

・その他
LINE_MAXで画面をクリアするが、何行目か数える変数Load_lineが関数内でインクリメントするので分かりづらい

<<ver1.2>>
(途中から読み込むようになり原因が分からないため放置)
改善したいところ、確認したいところ
・メニュー画面を指定のものにする
・テキストの囲いを作る(解決)
・真ん中にキャラが出てくるようにする(解決)
・case_flagがグローバル関数になっていること→initializeとload_firstの改善が必須
・select_optとcase_binaryの引数が多い(解決)
・case_binaryが関数分けされていないので、関数分けして見やすくする(解決)
・case_binaryのフローチャート作成(解決)
・*includeファイルにncurses.hなど3つの特射なヘッダファイルを置く(解決)
・text2.txtを用いてフラグがどのようになっているかを見る(解決)
・case_startの処理(Kscripter.c)
・system()を用いてシェルコマンドを使用できるようにする(ver1.3以降で実装予定)
・case_pattern[]の場所
・画面に表示する行数が少ないと本文が表示されなくなる
追加点
・列挙型FLAGの追加(function.h)
・

<<ver1.4>>
--Kscripterのソースコードの分割、変数名の変更、関数生成

・現在のスクリプトを記述するwrite_nowlog関数の追加
・b_log.cの中で新たに関数を生成
・save.cの中に新たに関数を生成
・dis_pause.cの中に新たに関数を生成
・strcmpの判定値SAME(=0)を定義
・select_optとcase_binaryが反応した時の返り値REACTを定義
・select_optの引数select_numberを消去(選択肢は3つになるため)
・変数Load_lineをLoad_countに変更
・case_binaryの引数をflag→c_flag、lflag→lc_flagに変更
・terminal_pointをterminal_countに変更(case_binary.c)
・pattern[]をx_case_y[]に変更(case_binary.c)
・Kscrpter.cの中に新たな関数を生成
・Load_first_display.cの中に新たな関数を生成

<<ver1.5>>
・現在のログを再記述する時のフレームの一部欠損を修正
・各ファイルの名前をマクロに定義
・一気に出力すると日本語表記になるが、一文字ずつ出力するようにすると文字化けする
　→半角文字を入れるとおかしくなる
・画面上でカーソルを非表示にした
・テキストが一定文字数を超えたら開業するようにする


