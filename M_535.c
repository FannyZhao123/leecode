/*
535. Encode and Decode TinyURL
Note: This is a companion problem to the System Design problem: Design TinyURL.
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.
*/

char* encode(char* longUrl) {
    char *e = longUrl + strlen(longUrl) - 1, *tiny = calloc(1, 10000);
    //update e to the location of first char after "/"
    while (*e-- != '/');
    printf("%s \n", e+2);
    strcat(strcpy(tiny, "https://tinyurl.com/"), e + 2);
    strcpy(tiny + strlen(tiny) + 1, longUrl);
    printf("%s", tiny + strlen(tiny) + 1);
    return tiny;
}

/** Decodes a shortened URL to its original URL. */
char* decode(char* shortUrl) {
    return shortUrl + strlen(shortUrl) + 1;
}

// Your functions will be called as such:
// char* s = encode(s);
// decode(s);

/*
stdout:
design-tinyurl 
https://leetcode.com/problems/design-tinyurl
*/