## آزمایش شماره یک : به حرکت درآوردن موتور الکتریکی 💡

### هدف 🎯

در این آزمایش می خواهیم با استفاده از ماژول <strong>درایور موتور L298N</strong> یک موتور DC را به حرکت درآوریم و سرعت و جهت چرخش آن را کنترل کنیم.

---

### مواد و وسایل مورد نیاز 🛠️

<div align="right">
<table>
<thead>
<tr>
<th>ردیف</th><th>قطعه</th><th>تعداد</th>
</tr>
</thead>
<tbody align="center">
<tr>
<td>1</td><td>برد آردوینو UNO</td><td>یک عدد</td>
</tr>
<tr>
<td>2</td><td>سیم جامپر</td><td>هشت عدد</td>
</tr>
<tr>
<td>3</td><td>کابل USB</td><td>یک عدد</td>
</tr>
<tr>
<td>4</td><td>درایور موتور L298N</td><td>یک عدد</td>
</tr>
<tr>
<td>5</td><td>موتور DC</td><td>یک عدد</td>
</tr>
<tr>
<td>6</td><td>منبع تغذیه DC</td><td>یک عدد</td>
</tr>
</tbody>
</table>
</div>

---

### توضیحات کلی 📝

برای کنترل موتور های الکتریکی در آردوینو، نیاز به استفاده از ماژول های درایور موتور داریم. یکی از این ماژول ها، مدل L298N می باشد که دو خروجی دارد یعنی با استفاده از آن می توانیم دو عدد موتور DC را به طور همزمان تنظیم کنیم.  
برای کنترل کامل یک موتور DC لازم است هم سرعت و هم جهت دوران موتور را کنترل کرد. برای کنترل سرعت از تکنیک PWM استفاده می کنیم و برای کنترل جهت چرخش موتور از تکنیک H-Bridge استفاده می کنیم.

---

### سورس کد 💻

```cpp
void setup() {
  for (int i = 8; i < 11; i++) {
    pinMode(i, OUTPUT);
    }
}

void loop() {
  digitalWrite(9, HIGH);  // full speed forward
  digitalWrite(8, LOW);
  analogWrite(10, HIGH);
  delay(1000);

  digitalWrite(9, LOW); // full speed backward
  digitalWrite(8, HIGH);
  analogWrite(10, i);
  delay(1000);

  for (int i=0; i<256; i++) {  // increased speed forward
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  analogWrite(10, i);
  delay(20);
  }
  delay(50);

  for (int i=0; i<256; i++) { // increased speed backward
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  analogWrite(10, i);
  delay(20);
  }
  delay(50);
}
```

---

### توصیف کد های برنامه 🧑🏻‍💻

در تابع setup پین های 8 تا 10 آردوینو را به عنوان خروجی تنظیم می کنیم. پین 9 برای IN1 و پین 8 برای IN2 و پین 10 برای تنظیم سرعت می باشد.  
در تابع loop در حالت اول، ورودی IN1 ولتاژ High و IN2 ولتاژ Low می گیرد بنابراین موتور ساعت گرد می چرخد. ورودی ENA نیز مستقیما ولتاژ High گرفته است بنابراین سرعت موتور در حداکثر مقدار ممکن است. در حالت دوم، سرعت مشابه حالت اول در حداکثر است و فقط ولتاژ IN1 و IN2 جا به جا شده است و بنابراین موتور به صورت معکوس ( پاد ساعت گرد ) می چرخد. در حالت سوم مشابه حالت اول موتور ساعت گرد می چرخد اما سرعت موتور ثابت نیست و از صفر شروع شده و هر 20 میلی ثانیه افزایش می یابد تا به 255 ( حداکثر سرعت ) برسد بنابراین در طول پنچ ثانیه از مینیمم تا ماکسیمم سرعت می رسد. در نهایت حالت چهارم نیز مشابه حالت اول می باشد و فقط جهت چرخش موتور تغییر می کند.

---

### شرح کارکرد مدار به صورت ویدیویی 🎥

<div align="center">
<img src="/media/microprocessor_19.gif">
</div>

---

### شماتیک مدار 🗺️

<br>

<div align="center">
<img src="/media/schematic_17.jpg" width="600px" height="500px">
</div>

---

### توضیحات شماتیک مدار ✒️

<ol>
<li>
اتصالات درایور موتور
<ul>
<li>ورودی 12 ولت به سر مثبت منبع تغذیه</li>
<li>ورودی Gnd به سر منفی منبع تغذیه</li>
<li>همچنین ورودی Gnd به پین Gnd آردوینو</li>
<li>ورودی ENA به پین 10 آردوینو</li>
<li>ورودی IN1 به پین 9 آردوینو</li>
<li>ورودی IN2 به پین 8 آردوینو</li>
<li>خروجی OUT1 به یکی از پایه های موتور DC</li>
<li>خروجی OUT2 به پایه دیگر موتور DC</li>
</ul>
</li>
<li>
اتصالات منبع تغذیه DC
<ul>
<li>سر مثبت به ورودی 12V درایور موتور</li>
<li>سر منفی به ورودی Gnd درایور موتور</li>
</ul>
</li>
</ol>

---

### نتیجه گیری 👀

کار کردن و تعامل با موتور های الکتریکی یکی از رایج ترین زمینه های سال های اخیر می باشد و به خصوص در علم رباتیک بسیار با آن سر و کار خواهیم داشت.  
یکی از مشکلات این آزمایش داغ شدن موتور DC بعد از تنها چند ثانیه کارکرد در بیشترین توان ممکن است.
