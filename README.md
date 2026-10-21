# 🔘 Serial-Controlled Dual LED

> **Arduino Project #29** — التحكم بـ LEDين عبر أوامر Serial Monitor

[![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white)](https://www.arduino.cc/)
[![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Level](https://img.shields.io/badge/Level-Beginner-green?style=for-the-badge)](https://github.com/S-mohannad)

---

## 📋 Description

مشروع يتيح للمستخدم التحكم بـ LEDين بشكل مستقل عبر Serial Monitor:

- يعرض قائمة الأوامر في كل دورة
- ينتظر المستخدم يدخل رقم (1–4)
- يُنفّذ الأمر المناسب على LED1 أو LED2
- يطبع الرقم المُدخل للتأكيد

---

## 🔌 Circuit

```
Arduino UNO
┌─────────────────┐
│            10 ●─┼──[220Ω]──💡 LED 1 ── GND
│            11 ●─┼──[220Ω]──💡 LED 2 ── GND
└─────────────────┘
```

- 💡 LED 1 على Pin 10 مع مقاومة 220Ω
- 💡 LED 2 على Pin 11 مع مقاومة 220Ω

---

## 💡 Concepts Used

- `Serial.parseInt()` — قراءة رقم صحيح من المستخدم
- `Serial.available()` — الانتظار حتى يُدخل المستخدم قيمة
- `while()` — تجميد البرنامج حتى وصول بيانات
- `if` متعدد — لتنفيذ الأمر المناسب بناءً على الرقم المُدخل
- `digitalWrite()` — تشغيل وإطفاء كل LED بشكل مستقل

---

## 📊 Behavior

| الرقم المُدخل | التأثير |
|--------------|---------|
| 1 | LED 1 يطفى (pin 10 LOW) |
| 2 | LED 1 يشتغل (pin 10 HIGH) |
| 3 | LED 2 يطفى (pin 11 LOW) |
| 4 | LED 2 يشتغل (pin 11 HIGH) |

---

## 🔗 Code

```cpp
int v;

void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  Serial.print("enter 1 to turn off led1 \n enter 2 to turn on led1 \n enter 3 to turn off led2 \n enter 4 to turn on led2");
  while (Serial.available() == 0) {}
  v = Serial.parseInt();
  if (v == 1) { digitalWrite(10, LOW); }
  if (v == 2) { digitalWrite(10, HIGH); }
  if (v == 3) { digitalWrite(11, LOW); }
  if (v == 4) { digitalWrite(11, HIGH); }
  Serial.print("\n v:");
  Serial.print(v);
}
```

---

## 🔧 How to Run

1. افتح **Arduino IDE**
2. وصّل LEDين على pin 10 و pin 11 مع مقاومة 220Ω لكل منهما
3. انسخ الكود والصقه في المحرر
4. اختر **Board:** Arduino UNO
5. اختر **Port** الصحيح
6. اضغط ⬆️ **Upload**
7. افتح **Serial Monitor** (9600 baud)
8. أدخل رقماً من 1 إلى 4 واضغط Enter للتحكم بالـ LEDs

---

## 👨‍💻 Author

**S-mohannad** — [@S-mohannad](https://github.com/S-mohannad)
