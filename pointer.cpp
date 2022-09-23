#include <iostream>

using namespace std;
// ví dụ về một hàm swap thay đổi giá trị của hai số sử dụng con trỏ 
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    int a = 1000;
    int b = 2000;
    int *ptr; // con tro ptr kieu integer   
    ptr = &a;
    cout << ptr << endl;
    cout << (*ptr)<< endl; // giai tham chieu, truy cap vao gia tri cua bien ma con tro dang tro toi
    // co the co nhieu con tro cung tro toi mot bien 
    // gia tri cua con tro la dia chi cua bien
    // "*" la toan tu giai  tham chieu cua con tro la gia tri cua bien ma no dang tro toi 
/*theo ý hiểu của mình, con trỏ dùng để cấp phát vùng nhớ động trong RAM của máy tính
khi làm việc với con trỏ ta không làm việc với giá trị của biến mà làm việc với vùng nhớ trên biến được con trỏ chỉ tới,
thay vì mỗi lần ta sử dụng biến bộ nhớ sẽ copy một vùng nhớ của biến gốc để gán giá trị và tương tác lên đó, 
thì con trỏ trỏ thẳng đến địa chỉ của biến và thay đổi giá trị trên đó, nên bộ nhớ không cần cấp thêm vùng nhớ cho biến (tiết kiệm tài nguyên)
nhưng lưu ý rằng con trỏ không làm giảm bộ nhớ, nó chỉ dùng lại phần bộ nhớ đó
*/
swap(&a,&b); 
/*
khi truyền đối số đối với hàm có tham số là con trỏ ( ở đây là swap() ) thì phải truyền địa chỉ,
vì ta hiểu đơn giản truyền tham số cho hàm là truyền giá trị cho tham số đó, ở đây GIÁ TRỊ CỦA CON TRỎ LÀ ĐỊA CHỈ CỦA BIẾN 
mà con trỏ đó đang chỉ tới.
*/
return 0;
/*
con trỏ this của lớp nào (class) thì sẽ trỏ đến lớp đó, con trỏ this dùng để tham chiếu đến đối tượng được gọi hàm thành phần 
*/

/*
(a+i) là con trỏ quản lý địa chỉ của mảng a[i]
CẤP PHÁT ĐỘNG :
trước khi hiểu cấp phát động và cú pháp thì ta sẽ bắt đầu với cấp phát tĩnh
*/
int a[1000000]; 
/*cấp phát tĩnh - khi đó máy sẽ bị tràn bộ nhớ stacks bởi vì:
kiểu integer yêu cầu các ô nhớ LIỀN NHAU và hơn kém nhau 4 byte, ví dụ bộ nhớ là một ma trận vuông 16x16
khi đó bộ nhớ chỉ cấp được 4 ô nhớ liên tiếp kề nhau thỏa mãn điều kiện kiểu integer là hơn kém nhau 4 byte
*/
// CẤP PHÁT ĐỘNG VÀ CÚ PHÁP
int *a = new int[1000000];
/*
Cấp phát động sẽ dựa trên nguyên lý của pointer ( con trỏ )
thay vì bộ nhớ phải cung cấp các ô nhớ LIỀN NHAU và hơn kém nhau 4 byte
thì con trỏ sẽ trỏ đến địa chỉ của các ô nhớ ngẫu nhiên trên toàn bộ nhớ để cấp phát một mảng thõa mản kiểu integer
vì một con trỏ có thể trỏ đến nhiều địa chỉ trên bộ nhớ, do đó có thể cấp phát đến khi nào hết bộ nhớ mà các ô nhớ không cần liền nhau
Chúng liền nhau nhưng về cốt lõi thì không liền nhau ( do pointer)
*/
}