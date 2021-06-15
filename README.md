# Chinese-chess-game-
Code thiếu nhi oop seminar thực hành

I. GIỚI THIỆU CHUNG
- Chương trình sử dụng ngôn ngữ C++
- Để chạy chương trình cần Visual Studio
- Chương trình xài thư viện iostream, Windows.h, string. Không cần cài thư viện gì thêm.

II. Hướng dẫn sử dụng

A. Luật cờ tướng:
1. Tốt: đi một ô mỗi nước. Nếu tốt chưa vượt qua sông, nó chỉ có thể đi thẳng tiến. Khi đã vượt sông rồi, 
	tốt có thể đi ngang 1 nước hay đi thẳng tiến 1 bước mỗi nước.

2. Pháo: Đi ngang và dọc giống như xe. Điểm khác biệt là nếu pháo muốn ăn quân, pháo phải nhảy qua đúng 
	1 quân nào đó. Khi không ăn quân, tất cả những điểm từ chỗ đi đến chỗ đến phải không có quân cản. 

3. Xe: Đi ngang hay dọc trên bàn cờ miễn là đừng bị quân khác cản đường từ điểm đi đến điểm đến. 

4. Mã: Đi ngang 2 ô và dọc 1 ô (hay dọc 2 ô và ngang 1 ô) cho mỗi nước đi. Nếu có quân nằm ngay bên cạnh 
	mã và cản đường ngang 2 (hay đường dọc 2), mã bị cản không được đi đường đó. 

5. Tượng: Đi chéo 2 ô (ngang 2 và dọc 2) cho mỗi nước đi. Tượng chỉ được phép ở một bên của bàn cờ, không
	 được di chuyển sang nửa bàn cờ của đối phương. Nước đi của tượng sẽ không hợp lệ khi có một quân
	 cờ nằm chặn giữa đường đi. 

6. Sĩ: Đi xéo 1 ô mỗi nước. Sĩ luôn luôn phải ở trong cung như Tướng. 

7. Tướng: Đi từng ô một, đi ngang hoặc dọc. Tướng luôn luôn phải ở trong phạm vi cung và không được ra ngoài.
	 Cung tức là hình vuông 2X2 được đánh dấu bằng đường chéo hình chữ X 

B. Cách chơi
- Game cờ tướng dành cho 2 người chơi. Chế độ chơi luân phiên theo lượt không giới hạn thời gian.

- Bắt đầu trò chơi thì bên mặc định đi trước là bên trắng (bên trên)

- Mỗi lượt đi người chơi sẽ chọn một loại quân cờ từ danh sách quân cờ theo thứ tự từ 1-7. Chọn một loại 
  quân cờ bằng cách nhập chỉ số. 

- Chương trình sẽ hiện ra danh sách các quân cờ có trong loại quân đấy. Chọn 1 trong các quân để đi.

- Chọn quân cờ bằng cách nhập 1 trong các tọa độ của các quân cờ theo danh sách đã được đưa ra. Nếu nhập 
  sai sẽ nhập lại.

- Tiếp theo người chơi chỉ cần nhập tọa độ quân cờ muốn đi tới (có thể là đi quân hoặc ăn quân) theo danh 
  sách đã đề ra. Nếu nhập sai sẽ nhập lại.

- Tương tự với người chơi thứ 2 đến khi ván game kết thúc.

- Ván game kết thúc khi có 1 trong 2 quân tướng bị ăn hoặc khi cả hai bên không còn các quân sĩ, pháo, xe,
  ngựa. 

NOTE: Khi bị chiếu thì quân tướng sẽ có màu chữ đại diện là đỏ và có thông báo cho người chơi bị chiếu.
