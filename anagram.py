def is_anagram(s1, s2):
    # Normalize the strings: remove spaces and convert to lower case
    s1 = s1.replace(' ', '').lower()
    s2 = s2.replace(' ', '').lower()
    return sorted(s1) == sorted(s2)