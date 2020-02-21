# hanoi_tower 河內塔
使用 C 語言寫的簡易版河內塔 hanoi_tower  
設定為三柱, 碟數則由使用者執行時輸入

linux 下編譯

>#gcc -o hanoi hanoi_tower.c  
>#./hanoi  
>input number of tower: 3  
>.......  
>tower A:  
>tower B:  
>tower C: 3 2 1  
>done, total 7 steps  

想法：
要將所有的碟(n個)由柱 A 搬到柱 C, 可以將問題拆解為
1. 將(n-1)個碟搬到柱 B
2. 將第 n 個碟搬到柱 C
3. 將(n-1)個碟搬到柱 C

因此可以用遞迴的方式來處理, 只要碟數不等於 1, 就繼續遞迴
