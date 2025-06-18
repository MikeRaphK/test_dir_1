def is_anagram(s1, s2):
    # Remove spaces and convert to lowercase for case-insensitivity
    cleaned_s1 = ''.join(s1.split()).lower()
    cleaned_s2 = ''.join(s2.split()).lower()
    return sorted(cleaned_s1) == sorted(cleaned_s2)
