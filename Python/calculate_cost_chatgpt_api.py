from forex_python.converter import CurrencyRates

c = CurrencyRates()

TOKEN_SIZE = 5


def gpt3_5(token_num):
    return 0.002*token_num/1000


'''
context: 8k or 32k
usage: prompt or completion
'''


def gpt4(token_num, context, usage):
    result = 0.003*token_num/1000
    if context == "32k":
        result *= 2
    if usage == "completion":
        result *= 2
    return result


def usd_to_try(dolar):
    return c.convert("USD", "TRY", dolar)


if __name__ == "__main__":
    print(usd_to_try(gpt3_5(1000)))
