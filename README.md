# bento

Beforehand, please do not use this program in production or for anything security related. This program is intended for research and education purpose only.

## How does this cipher works ?

Just like playing bento. Seriously, this cipher scams you the same way a bento player does. It's so unstable that the decoding is not working almost every time !

The program takes as input:
- a plaintext of any size
- a key of any size

The program returns a string of any size.

Let's see how it works with `ABCDEF` as plaintext and `13579` as the key:
- We start at index `0` of both the plaintext.
- We then read the first element of the key which is `1`.
- The value at the index `0` is swapped with the index `1`.
    - The operation is: `0 + 1 = 1`
- The modified plaintext is now `BACDEF`.
- We are now at index `1` and we read that the next element of `key` is `3`. Doing `1 + 3` gaves us `4` so we swap `A` with `E` giving `BECDAF`.
- Now that we are at position `4`, we have a problem. `4 + 5 = 9`. This is solved by wrapping around the array by doing `(4 + 5) % len(plaintext)` giving us the value `3`.
- The array is now `BECADF`, I'll show the last steps for you directly: `BECDAF`, `BACDEF`.

The program does one more thing: it jumps to a next value and do the "swapping" again starting from this new index. This jump by default is `3` and can be modified in the source code with the `INTERVAL` macro.

## Why i made this program ?

I wanted to do a transposition cipher and as I love celullar automatons, I wanted to do a mix betewwn the two. And here we are.
If you want to contribute trying to stabilize this algorithm, making it reliable, feel free to PR or issuing me throught this repository.

In the end, have fun with it !
