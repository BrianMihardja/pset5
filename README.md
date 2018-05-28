# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

An artificial long word said to mean a lung disease caused by inhaling very fine ash and sand dust.

## According to its man page, what does `getrusage` do?

Gets resource usage

## Per that same man page, how many members are in a variable of type `struct rusage`?

16

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

To find the time of start and of finish.

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

Firstly, the user inputs an argument containing the dictionary and variable.
Then, the program allocates the word into variable array 'text'.
It then reads the file character by character, only adding in the character to the array 'word[index]' if it is an alphabet or apostrophe that is not at the start of the word.
However, the program stops writing the character into the word[index] array if the amount of letters exceed 45+1 characters.
It instead loops through until the end of file is reached or the character is no longer an alphabet.

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

Because with fscanf(), it is harder to find the end of file or if there are special non-alphabet symbols that is 'scanned'.

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

To make sure that the variables aren't changed or deleted within the speller.c file by the program.
