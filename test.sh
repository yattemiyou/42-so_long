#!/bin/sh

echo '---TEST:Wrong Arguments---'
T01="./so_long"
echo "$T01 :\n`$T01`"
T02="./so_long .MAP/ok_min1.ber .MAP/ok_min2.ber"
echo "$T02 :\n`$T02`"
echo "\n"

echo '---TEST:Wrong Filename Extenrion---'
T11="./so_long ./maps/ng_ext1."
echo "$T11 :\n`$T11`"
T12="./so_long ./maps/ng_ext2.b"
echo "$T12 :\n`$T12`"
T13="./so_long ./maps/ng_ext3.be"
echo "$T13 :\n`$T13`"
T14="./so_long ./maps/ng_ext4.berr"
echo "$T14 :\n`$T14`"
T15="./so_long \"\""
echo "$T15 :\n`$T15`"
echo "\n"

echo '---TEST:File Not Found---'
T21="./so_long ./maps/Not_exist_file.ber"
echo "$T21 : \n`$T21`"
echo "\n"

echo '---TEST:Walls Are Not Square'
T301="./so_long ./maps/ng_notsqr1.ber"
echo "$T301 : \n`$T301`"
T302="./so_long ./maps/ng_notsqr2.ber"
echo "$T302 : \n`$T302`"
T303="./so_long ./maps/ng_notsqr3.ber"
echo "$T303 : \n`$T303`"
T304="./so_long ./maps/ng_notsqr4.ber"
echo "$T304 : \n`$T304`"
T305="./so_long ./maps/ng_notsqr5.ber"
echo "$T305 : \n`$T305`"
T306="./so_long ./maps/ng_notsqr6.ber"
echo "$T306 : \n`$T306`"
T307="./so_long ./maps/ng_notsqr7.ber"
echo "$T307 : \n`$T307`"
T308="./so_long ./maps/ng_notsqr8.ber"
echo "$T308 : \n`$T308`"
T309="./so_long ./maps/ng_notsqr9.ber"
echo "$T309 : \n`$T309`"
T310="./so_long ./maps/ng_notsqr10.ber"
echo "$T310 : \n`$T310`"
T311="./so_long ./maps/ng_notsqr11.ber"
echo "$T311 : \n`$T311`"
T312="./so_long ./maps/ng_notsqr12.ber"
echo "$T312 : \n`$T312`"
T313="./so_long ./maps/ng_notsqr13.ber"
echo "$T313 : \n`$T313`"
T314="./so_long ./maps/ng_notsqr14.ber"
echo "$T314 : \n`$T314`"
T315="./so_long ./maps/ng_notsqr15.ber"
echo "$T315 : \n`$T315`"
T316="./so_long ./maps/ng_notsqr16.ber"
echo "$T316 : \n`$T316`"
T317="./so_long ./maps/ng_notsqr17.ber"
echo "$T317 : \n`$T317`"
T318="./so_long ./maps/ng_notsqr18.ber"
echo "$T318 : \n`$T318`"
T319="./so_long ./maps/ng_notsqr19.ber"
echo "$T319 : \n`$T319`"
echo "\n"

echo '---TEST:map contains invalid character'
T41="./so_long ./maps/ng_ivchr1.ber"
echo "$T41 : \n `$T41`"
echo "\n"

echo '---TEST:C,E or P character was not found'
T51="./so_long ./maps/ng_Cnotfound.ber"
echo "$T51 : \n `$T51`"
T52="./so_long ./maps/ng_Enotfound.ber"
echo "$T52 : \n `$T52`"
T53="./so_long ./maps/ng_Pnotfound.ber"
echo "$T53 : \n `$T53`"
echo "\n"

echo '---TEST:map contains duplicate character'
T61="./so_long ./maps/ng_Edupchr.ber"
echo "$T61 : \n `$T61`"
T62="./so_long ./maps/ng_Pdupchr.ber"
echo "$T62 : \n `$T62`"
echo "\n"

echo '---TEST:map can not reach C'
T71="./so_long ./maps/ng_Cnotreachable1.ber"
echo "$T71 : \n `$T71`"
T72="./so_long ./maps/ng_Cnotreachable2.ber"
echo "$T72 : \n `$T72`"
T73="./so_long ./maps/ng_Cnotreachable3.ber"
echo "$T73 : \n `$T73`"
echo "\n"

echo '---TEST:map can not reach E'
T81="./so_long ./maps/ng_Enotreachable.ber"
echo "$T81 : \n `$T81`"
echo "\n"

# echo '---TEST:normaly complex map'
# T91="./so_long ./maps/ok_cmplx1.ber"
# echo "$T91 : \n `$T91`"
# T92="./so_long ./maps/ok_cmplx2.ber"
# echo "$T92 : \n `$T92`"
# echo "\n"

# echo '---TEST:normaly simple map'
# TA1='./so_long ./maps/ok_min1.ber'
# echo "$TA1 : \n `$TA1`"
# TA2='./so_long ./maps/ok_min2.ber'
# echo "$TA2 : \n `$TA2`"
# echo "\n"
