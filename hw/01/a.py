from math import exp
from math import log

def calculate_values(input_list):
    for line in input_list:
        if line == 'E':
            break

        values = line.split(' ')
        if 'T' in values and 'D' in values:
            T = float(values[values.index('T') + 1])
            D = float(values[values.index('D') + 1])
            e = 6.11 * exp(5417.7530 * ((1/273.16) - (1/(D+273.16))))
            h = (0.5555) * (e - 10.0)
            H = T + h
        elif 'T' in values and 'H' in values:
            T = float(values[values.index('T') + 1])
            H = float(values[values.index('H') + 1])
            h = H - T
            e = h / 0.5555 + 10.0
            D = 1 / (1/273.16 - (log(e/6.11) / 5417.7530)) - 273.16
        else:
            D = float(values[values.index('D') + 1])
            H = float(values[values.index('H') + 1])
            e = 6.11 * exp(5417.7530 * ((1/273.16) - (1/(D+273.16))))
            h = 0.5555 * (e - 10.0)
            T = H - h

        print(f'T {T:.1f} D {D:.1f} H {H:.1f}')

# Read input until 'E' is encountered
lines = []
while True:
    line = input().strip()
    if line == 'E':
        break
    lines.append(line)
calculate_values(lines)