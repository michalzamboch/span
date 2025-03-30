# Span

## What it is?
- A very lightweight abstraction of a contiguous sequence of values of type T somewhere in memory.
- Basically a struct { T * ptr; std::size_t size; } with a bunch of convenience methods.
- A non-owning type (i.e. a "reference-type" rather than a "value type"):
It never allocates nor deallocates anything and does not keep smart pointers alive.
- Simillar to string_view
- Also in other languages (C#)

## When to use span

## When not to use span

## Example
