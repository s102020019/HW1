# HW1
## Overview
* 運用可調整程式，實現Q1暖色系濾鏡
* 運用可調整程式，實現Q3電影感色調

## Implementation
* For Q1 :<br>
先運用opencv函式庫讀取圖檔，並把資料存進一個矩陣Mat的資料型態，接著宣告一個uchar的指標指向Mat裡的資料進行調整。為了方便，設定變數來更改每個資料的值。其中每個指向的目標，又包含三種不同資料，故宣告三個變數以利調整。以下是部分的C++程式:
```
  float a,b,c,val;
	for (int i = 0; i<image.rows; i++){
			pixptr = image.ptr<uchar>(i);
			for (int j = 0; j<image.cols; j++){
				val = pixptr[0] * a;
				if (val > 255){ pixptr[0] = 255; }
				else{ pixptr[0] = pixptr[0] * a; }
				
				val = pixptr[1] * b;
				if (val > 255){ pixptr[1] = 255; }
				else{ pixptr[1] = pixptr[1] * b; }

				val = pixptr[2] * c;
				if (val > 255){ pixptr[2] = 255; }
				else{ pixptr[2] = pixptr[2] * c; }
		
				pixptr += 3;
			}
		}
```
* pixptr[i],i=0~2分別代表藍綠紅，選定調整的圖是HW01.ppt裡的Robot.png。為了實現暖色調，我嘗試調高紅色的倍數，即c值，但是原圖本身圖像紅色比例很高。在機器人手臂的部分，紅色超過255，最後會只顯示綠色，所以加上限制條件，如果紅色大於255，就讓值等於255。pixptr[i]本身是uchar型別，所以當輸入的值超過255，輸出就不會有任何東西，故需要一個float型別的變數val，幫我判斷是否輸入的值會超過255。<br>
測試的方式是，從B10G10R105開始，BGR分別代表藍綠紅，其後接的數字第一個位數皆是個位數，第二個或三或四都是小位數。因為想讓整體畫面偏黃色，所以只進行調整B的程序而G不改變一直為1.0，所以分類有B08、B09、B10三個資料夾，最後把覺得最接近暖色調的結果貼在下方Display。

* For Q2 :<br>
 





## Theory


## Disparity result


## Reference
