/* cv-限定符
const：
 表明内存被初始化后，程序便不能再对他进行修改。

 在C++中，const限定符对默认存储类型稍有影响。在默认情况下全局变量的连接性为外部的，但是const
 全局变量的连接性为内部。也就是说，在C++看来，全局const定义就像使用了static说明符一样。

 C++修改了常量类型的规则，让程序员更轻松。例如，假设将一组常量放在头文件中，并在同一个程序的多个文件中使用该头文件。
 那么，预处理器将头文件的内容包含到每个源文件后，所有的元文件都将包含雷士下面的定义：
   const int fingers = 10;
   const char * warning = "wak";
 如果全局const声明的连接性像常规变量那样是外部的，则根据但定义规则，这将出错。也就是说，智能有一个文件可以包含前面的声明，而
 其他文件必须使用extern关键字来提供引用声明。另外，只有为使用extern关键字的声明才能初始化。

 因此，需要为某个使用一组定义，而其他文件使用另一组声明，然而，由于外部定义的const数据的连接性为内部的，因此可以在所有文件中
 使用相同的声明

 内部连接性还意味着，每个文件都有自己的一组常量，而不是所有文件共享一组常量。每个定义都是其所属文件私有的，这就是能够将常量
 定义放在头文件中的原因，这样，只要在两个源代码文件中包含同一个头文件，则它们将获得同一组常量。

 如果处于某种原因，程序员希望某个常量的连接性为外部的，则可以使用extern关键字来覆盖默认的内部连接性：
   extern const int state = 50;
 在这种情况下，必须在使用所有该常量的文件中使用extern关键字来声明它。这与常规变量不通，定义常规外部变量是，不必使用
 extern关键字，但在使用该变量的其他文件中必须使用extern。然而，请记住，鉴于单个const在多个文件之间共享，因此只有一个文件可
 对其进行初始化
volatile:
 表明即使程序代码没有对内存单元进行修改，其值也可能发生变化。

mutable:
 表明即使结构（类）变量为const，其成员也可以被修改。
*/


/* 函数的链接性
  所有的函数的存储持续性都是静态的，即在程序执行期间一直存在

  在默认情况下，函数的连接性为外部的，即可以在文件间共享。

  可以使用关键字static将函数的连接性设置为内部的，使它只能在一个文件中使用。（必须同时在原型和函数定义中使用该关键字）
*/

/* C++在哪里查找函数呢？
  假设在程序的某个文件中调用一个函数，C++将去哪里寻找该函数的定义呢？ 如果该文件中的函数原型指出该函数是静态的，则
  编译器将只在该文件中查找函数定义；否则，编译器将在所有的程序文件中查找。如果找到两个定义，编译器将发出错误消息，因为每个外部函数只能有
  一个定义，如果在程序文件中没有找到，编译器将在库中搜说。这意味着如果定义了一个与库函数同名的函数，编译器将使用程序员定义的潘板，而不是库
  函数。
*/

/*
另一种形式的链接性--称为语言链接性 也对函数有影响。首先

*/
