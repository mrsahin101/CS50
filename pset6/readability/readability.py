from cs50 import get_string

answer = get_string("Text:")

words = 0
sentences = 0
letters = 0

mylist = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l",
          "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"]
          
special_list = ["!", "?", "."]

for i in answer:
    if i == " ":
        words += 1
    if i.lower() in mylist:
        letters += 1
    if i in special_list:
        sentences += 1

words += 1
avg_letters = 100 / float(words)
avg_letters *= letters

avg_sentences = 100 / float(words)
avg_sentences *= sentences

grade = ((0.0588) * avg_letters) - ((0.296) * avg_sentences) - (15.8)
grade = round(grade)

if grade < 1:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print(f"Grade: {grade}")
