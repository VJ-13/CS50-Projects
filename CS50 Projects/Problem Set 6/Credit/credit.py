from cs50 import get_string

credit = get_string("Number: ");

copy_credit = credit[::-1]
every_other_sum = sum([(int(x) * 2 ) // 10 + ((int(x) * 2) % 10) for x in copy_credit[1::2]])
first_sum = sum ([int(x) for x in copy_credit[0::2]])
total_sum = every_other_sum + first_sum

if total_sum % 10 == 0:
    if len(credit) == 15 and credit[0:2] in ["34", "37"]:
        print("AMEX")
    elif len(credit) == 16 and 51 <= int(credit[0:2]) <= 55:
        print("MASTERCARD")
    elif len(credit) in [13, 16] and credit[0] == "4":
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")

