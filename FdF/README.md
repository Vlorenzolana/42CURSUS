**RESSOURCES TO LEARN**

***From CODAM***
**Download and build MLX42 in Terminal>>**
>>git clone https://github.com/codam-coding-college/MLX42.git<br>
>>cd MLX42<br>
>>cmake -B build # build here refers to the outputfolder.<br>
>>cmake --build build -j4 # or do make -C build -j4<br>
**Compile: gcc yourprogram.c ./yourpathto:libmlx42.a -I/yourpathto:includefolder -ldl -lglfw**<br>
>>gcc main.c ./MLX42/build/libmlx42.a -I/home/vlorenzo/_42CURSUS/fdf/MLX42/include -ldl -lglfw -pthread -lm<br>

***Some links to get started***<br>
https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html<br>
https://m4nnb3ll.medium.com/fil-de-fer-fdf-the-first-graphical-project-at-42-the-network-5cce69203448<br>
https://medium.com/@amehri_tarik/fdf-42-a-detailed-walkthrough-7184cca317fc<br>
