**RESSOURCES TO LEARN**

***From CODAM***
**Download and build MLX42 in Terminal>>**
>>git clone https://github.com/codam-coding-college/MLX42.git<br>
>>cd MLX42<br>
>>cmake -B build # build here refers to the outputfolder.<br>
>>cmake --build build -j4 <br>
<br>

***NOTICE NO LEAKS BUT FREE ISSUES***
>>https://github.com/codam-coding-college/MLX42/discussions/140<br>

**Compile yourprogram in Terminal>>** <br>
>>**Copy the code of the CODAM example and save yourprogram.c:>>** <br>
>>https://github.com/codam-coding-college/MLX42?tab=readme-ov-file#example<br>
>>**Please check the path of your .h, will be something like this>>** <br>
>>#include "MLX42/include/MLX42/MLX42.h"<br>
>>**Compile in Terminal>>** <br>
>>gcc yourprogram.c ./yourpathto:libmlx42.a -I/yourpathto:includefolder -ldl -lglfw -pthread -lm<br>
>>gcc main.c ./MLX42/build/libmlx42.a -I/home/vlorenzo/_42CURSUS/fdf/MLX42/include -ldl -lglfw -pthread -lm<br>

***Some links to get started***<br>
https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html<br>
https://m4nnb3ll.medium.com/fil-de-fer-fdf-the-first-graphical-project-at-42-the-network-5cce69203448<br>
https://medium.com/@amehri_tarik/fdf-42-a-detailed-walkthrough-7184cca317fc<br>
