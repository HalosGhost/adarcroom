=========
adarcroom
=========

``adarcroom`` is a native C/ncurses port of `Adarkroom <http://adarkroom.doublespeakgames.com/>`_.
The goal of this project is truly to be a port, not a clone.
However, some license will be taken when I feel that the style can be improved (e.g., renaming paricular items in-game).
As an additional note, in the spirit of terminal-based applications, I intend to extend the current interface to include vim-like keybinds.

Building
========
Ideally, this port will be entirely native and will only rely on ncurses (a version new enough to support wide characters).
However, I use `tup <http://gittup.org/tup/>`_ as a build system; so, you will need to have a copy of ``tup`` in order to build the project (or you can manually run the compiler commands).

For the sake of ``-Weverything``, this project has officially moved to using ``clang``.
While other compilers are probably still capable of building it just fine, it will only be tested using the latest version of ``clang``.

In order to build the project, you can run the following steps::

    git clone 'https://github.com/HalosGhost/adarcroom'
    cd adarcroom
    tup upd

After running ``tup upd``, the binary ``adarcroom`` will be present in the ``src`` directory.

Current Status
==============
At the moment, I am still implementing the basic mechanics (most of the mechanics for *A Room* and *Outside* are implemented).
The next step is to create the basic interface (for which a placeholder layout already exists) in ncurses so that the early parts of the game are actually playable.
To be clear, this means that, so far, this game is not playable.

See ``TODO.rst`` for a status of what still must be done.
*Note*: if you have not played the game already, there will be spoilers in this list.
