import re

from collections import Counter

with open("data.txt", "r", encoding="utf-8") as file:

    text = file.readlines()

    operator_codes = []

for line in text:

   match = re.search(r"(?:\+7|8)[\s\-]*\(?(\d{3})\)?", line)

   if match:

       code = match.group(1)

       operator_codes.append(code)



counts = Counter(operator_codes)

top_code = counts.most_common(1)

if top_code:

    code, frequency = top_code[0]

    print(f"Самый популярный код оператора: {code} (встречается {frequency} раз)") 
