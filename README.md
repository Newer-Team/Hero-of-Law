# Hero of Law Source Code

This is version **1.10** of Hero of Law.

Versions of the NPCMaker JSON file including the message data from more recent game versions, up to v1.21, are also provided in the `Scripts` folder. While the game can be built and played with these, they haven't been tested thoroughly, and may have incompatibilities with the v1.10 code in places.

## Building

Tested on WSL.

1. Install the toolchain:
* `cd ~`
* `sudo apt-get install git gcc unzip mercurial automake libelf-dev libperl-dev libgtk2.0-dev libgmp-dev libmpfr-dev`
* `git clone https://github.com/glankk/n64.git`
* `cd n64`
* `./install_deps`
* `./configure --prefix=/opt/n64 --enable-vc`
* `sudo make toolchain-all`
* `sudo make toolchain-install`
* `sudo make install-sys`
* `sudo rm -rf /opt/n64/mips64/include/z64hdr`
* `git clone https://github.com/z64tools/z64hdr.git `
* `sudo mkdir /opt/n64/mips64/include/z64hdr `
* `sudo mv -f z64hdr/* /opt/n64/mips64/include/z64hdr && sudo rm -rf z64hdr`
* `cd ..`
* `git clone https://github.com/z64utils/nOVL.git`
* `cd nOVL`
* ``gcc -o novl -s -Os -DNOVL_DEBUG=1 -flto src/*.c `pkg-config --cflags --libs libelf glib-2.0` ``
* `sudo cp novl /opt/n64/bin/`
* `echo -e '\nexport PATH="/opt/n64/bin:$PATH"' >> ~/.bashrc`
2. Move to a folder outside of the WSL filesystem. Then, run `git clone https://github.com/Newer-Team/Hero-of-Law.git`
3. Go into /Build and place `oot-1.0-dec.z64` there. This has to be a 1.0 US Zelda Ocarina of Time ROM, decompressed.
4. Run `python3 prepare.py`
5. Get [this](https://github.com/skawo/OoT-NPC-Maker/releases/tag/v.3.702.627) release of NPC Maker. Copy the NPCMaker 3.702 folder from within it to `Tool/` and rename it to "`NPCMAKER`".
6. [Optional] Obtain a WAD of Hero of Law by patching an Ocarina of Time WAD on [our website](https://newerteam.com/hol/) and put it into `/Build/tool/gzinject` as "`Zelda Ocarina N64 NTSC.wad`".
7. [Optional] Obtain the Wii common key, and put it as `common_key.bin` in `/Build/tool/gzinject`.
8. Run `./rebuild.sh -a -r`
