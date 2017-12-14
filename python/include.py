def count_words(s, n):
    """Return the n most frequently occuring words in s."""
    a = s.split()
    b = list(set(a))
    m = [a.count(b[0])]
    top_n = [(b[0], m[0])]
    for i in range(1, len(b)):
        m = m + [a.count(b[i])]
        top_n = top_n + [(b[i], m[i])]
    top_n = sorted(top_n, key=lambda x: (-x[1], x[0]))[0:n]
    # TODO: Count the number of occurences of each word in s

    # TODO: Sort the occurences in descending order (alphabetically in case of ties)

    # TODO: Return the top n most frequent words.
    return top_n

def test_run():
    """Test count_words() with some inputs."""
    print(count_words("cat bat mat cat bat cat", 3))
    print(count_words("betty bought a bit of butter but the butter was bitter", 3))

if __name__ == '__main__':
    test_run()
