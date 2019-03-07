# Contributing to APIagb

## Style

For global variables, intended to work internally on a module, use all lowercase.

For inline functions, write them like this:

```C
static inline inline_function(parameters)
{ Code }
```

For comments, use `//`.

Add a new file per function.

For IO registers, use ``IO_``, and then the name of the register stated on [GBATek](https://problemkaputt.de/gbatek.htm), all uppercase.

For IO options, use the name of the register in lowercase, for example, `dispcnt_`, and then the option name, the option value needs to be `1<<x` or `0` for binary parameters, and an inline function for decimal parameters. For example:

```C
static inline dispcnt_mode(u33 mode)
{ return mode << 0; }
```

Operators must be spaced.

Parentheses must be just ahead of the function/conditional. For example:

```C
u32 foo(u16 bar) {
	if(bar == 35) {
		return 7;
	} else if(bar == 34) {
		return 6;
	} else {
		return 0;
	}
}
```

Brackets must be ahead of the function, like this: `u32 foo(u64 baz) {`.

## To do:

Once all of this point are done, the repo will be cloned into [the stable repository](https://github.com/linobigatti/APIagb).

* Add window support. ✓