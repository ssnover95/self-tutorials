# Compiling Rust for MSP430
## Links
- https://github.com/rust-embedded/msp430-quickstart

## Tools
I downloaded Code Composer Studio to have access to the Launchpad drivers for Linux. My path for the drivers after installing CCSv8 was: `/home/ssnover/tools/ccs/ccsv8/ccs_base/DebugServer/drivers`

I also used mspdebug for flashing the board.

I installed the msp430 rust-std core with 

```
rustup default nightly
rustup target add msp430-none-elf
```

## Modifications to Existing Examples

Next, I cloned the msp430-quickstart repository. It required an implementation of `panic_handler` as it was out of date and using the `panic_implementation` feature. I copied `examples/blinky.rs` to `src/main.rs` and added the following to the top:

```
use core::panic::PanicInfo;

#[panic_handler]
fn panic(info: &PanicInfo) -> ! {
    
    loop {}
}
```

Then I commented out a few lines in `Cargo.toml`:

```
#[dependencies.msp430-rt]
#features = ["abort-on-panic"]
#version = "0.1.0"
```

## Flash the ELF to the Launchpad

Then I was able to build my blink application in `msp430-quickstart` with `xargo build`. The resulting ELF file was placed under `msp430-quickstart/target/msp430-none-elf/debug/` 

Finally, I flashed the board with `mspdebug`.

```
LD_LIBRARY_PATH=/home/ssnover/tools/ccs/ccsv8/ccs_base/DebugServer/drivers mspdebug tilib 'prog rust-embedded/msp430-quickstart/target/msp430-none-elf/debug/msp430-quickstart'
```

I'm just getting started in Rust and especially Rust Embedded. I hope to have more work and tutorials coming soon!
