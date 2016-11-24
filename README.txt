1.the constructor of the program
  half_edge_structure.h: 定义半边数据结构，包括Solid、Face、Loop、HalfEdge、Vertex。
  elar_operator.h:定义了五个最基本的欧拉操作mvfs、mev、mef、kemr 和 kfmrh 以及一个扫成操作。
  model.h:主要实现从input.txt读入点的数据然后构造成完整的半边数据结构。
  output.h:将构造成的半边数据结构按照给定的要求输出到D:/solid.brp，然后可以使用老师给定的软件打开进行验证。
  input.txt:主要存储的是点的坐标信息，可以同过修改此文件来生成不同的三维带洞模型。
  
2.input.txt
  第一行包括一个整数n，表示外环有几个点给成，然后是n行，每行三个double值，表示一个点的xyz坐标。
  然后是一个整数m表示内环的数目。
  下面为m个内环的数据，每个内环由一个整数开头，表示这个内环包括的点的个数，下面一次是每个点的坐标，跟上面的外环格式相同。
  下面为三个double值，表示扫成的方向，可以同过改变该值来决定扫成的方向。
  最后一行为一个整形值，表示扫成的距离。
  
3.output.txt
  最后生成的文件存储路径：D：/solid.brp，可以直接使用已有软件直接打开该文件进行检验建模结果。

  后期添加opengl绘制的功能。

![image](https://github.com/iaccepted/cad/blob/master/screenshot/result.jpg)