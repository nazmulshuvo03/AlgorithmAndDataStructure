########### Bloom Filters and Pokemon ###############

import pyhash

bit_vector = [0] * 20
print(bit_vector)

#Non cryptographic hash functions (Murmur and FNV)
fnv = pyhash.fnv1_32()
murmur = pyhash.murmur3_32()

# Calculate the outputs of FNV and Murmur hash functions for Pikachu and Charmander
fnv_pika = fnv("Pikachu") % 20
fnv_char = fnv("Charmander") % 20

murmur_pika = murmur("Pikachu") % 20
murmur_char = murmur("Charmander") % 20

print(fnv_pika, fnv_char, murmur_pika, murmur_char)

bit_vector[fnv_pika] = 1
bit_vector[fnv_char] = 1

bit_vector[murmur_pika] = 1
bit_vector[murmur_char] = 1

print(bit_vector)

#A wile Bulbasor appears
fnv_bulb = fnv("Bulbasor") % 20
murmur_bulb = murmur("Bulbasor") % 20

print(fnv_bulb, murmur_bulb)


if(bit_vector[fnv_bulb] == 1 and bit_vector[murmur_bulb] == 1):
    print('Already There')
elif(bit_vector[fnv_bulb] == 0 or bit_vector[murmur_bulb] == 0):
    print('Catch')
