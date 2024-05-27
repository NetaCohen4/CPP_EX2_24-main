# מטלה 2 - גרפים והעמסת אופרטורים

נטע כהן netaco432@gmail.com  325195774

בתוכנית זו מימשתי מספר אופרטורים עבור המחלקה Graph. 
המחלרה Graph היא מחלקה המממשת גרף באמצעות מטריצת שכנויות, ויודעת לבצע אלגוריתמים בסיסיים על גרף כגון dfs, bfs.

פירוט האופרטורים ואופן התנהגותם:

- אופרטור השמה: =
באמצעותו ניתן להעתיק גרף לתוך גרף בהעתקה עמוקה.

- אופרטור השמה: =
באמצעותו ניתן להעתיק גרף לתוך גרף בהעתקה עמוקה.

- אופרטורים חשבוניים על גרפים: +, -, *
הגרפים מיוצגים בעזרת מטריצת שכנויות, לכן המימוש של אופרטורים אלה הוא בהתאם לפעולות על מטריצות, ופעולות אלה מוגדרות רק עבור מטריצות מאותו סדר גודל, אחרת נזקרת שגיאה.
לפעולות אלה מוגדר גם +=, -=

- פעולות על גרף יחיד: כפל בסקלר, פלוס אונארי, מינוס אונארי
בכפל בסקלר אנו כופלים את כל צלעות הגרף בסקלר, אם הוא 0 מוחזרת שגיאה. מוגדר גם *=.
פלוס אונארי לא משנה את מטריצת השכונויות בכלל, ומינוס אונארי מכפיל את כל הצלעות ב1-.

- הגדלה ב-1 (++) והקטנה ב-1 (--) לפני ואחרי גרף. 
פעולה זו תגדיל או תקטין ב-1 את כל המשקלים של הצלעות בגרף. במימוש שלי אני לא מגדילה או מקטינה צלע שמשקלה 0 - כלומר צלע שאינה קיימת, וכמו כן במקרה במקרה בו הגדלה או הקטנה של משקל צלע יגרום לאיפוס הצלע תוחזר שגיאה.
ההבדל בין ++/-- לפני הגרף לבין אחרי הגרף הוא כמובן הגרף המוחזר- כאשר הפעולה לפני הגרף יוחזר הגרף המעודכן, וכאשר היא אחרי הגרף יוחזר הגרף המקורי.

- שישה אופרטורי השוואה: <, =<, >, =>, ==, =!. הגרפים מושווים בצורה הבאה:

  1. גרפים G1 ו-G2 ייקראו שווים אם יש להם אותו מספר קדקדים ואותן צלעות בדיוק - זאת אומרת שמטריצת השכנויות זהה לחלוטין.
  2. גרף G2 גדול מגרף G1 אם הגרף G1 מוכל ממש בגרף G2. אם אף גרף לא מוכל ממש בשני והגרפים לא שווים, אז גרף G2 גדול מגרף G1 אם מספר הצלעות ב-G2 גדול ממספר הצלעות ב-G1. אם בכל זאת מספר הצלעות זהה, אז הגרף G2 גדול מהגרף G1 אם המטריצה המייצגת של G2 בעלת סדר גודל גבוה יותר משל G1.


- אופרטור פלט - הדפסה של הגרף כמטריצת שכנויות.


כמו כן, עליכם לכלול גם את הקובץ `Algorithms.cpp` מהמטלה הקודמת ולראות כיצד הפונקציות שהגדרתם בפעם הקודמת משתנות עכשיו. בנוסף לקבצים של המטלה אתם נדרשים להגיש גם קובץ README המתאר את אופן המימוש ואת החלוקה שביצעתם בקוד (סוג של מדריך משתמש).
עליכם לכתוב בתחילת כל קובץ את מספר תעודת הזהות שלכם ואת המייל. אי עמידה בהנחיות תגרור הפחתה בציון.
בהצלחה!

