#!/usr/bin/env python3
"""Génère les icônes launcher Android / iOS / web à partir du logo Afrique AFRILANG."""
from __future__ import annotations

from pathlib import Path

from PIL import Image

ROOT = Path(__file__).resolve().parents[1]
BRAND = ROOT / 'assets' / 'brand'
ANDROID_RES = ROOT / 'android' / 'app' / 'src' / 'main' / 'res'
IOS_SET = ROOT / 'ios' / 'Runner' / 'Assets.xcassets' / 'AppIcon.appiconset'
WEB_ICONS = ROOT / 'web' / 'icons'
WEB_FAVICON = ROOT / 'web' / 'favicon.png'

NAVY = (26, 35, 48)


def resize(src: Image.Image, size: int) -> Image.Image:
    return src.resize((size, size), Image.Resampling.LANCZOS)


def save_png(im: Image.Image, path: Path) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    im.save(path, 'PNG')
    print(f'  {path.relative_to(ROOT)} ({im.size[0]}x{im.size[1]})')


def write_android(transparent: Image.Image, foreground: Image.Image) -> None:
    densities = {
        'mipmap-mdpi': 48,
        'mipmap-hdpi': 72,
        'mipmap-xhdpi': 96,
        'mipmap-xxhdpi': 144,
        'mipmap-xxxhdpi': 192,
    }
    for folder, size in densities.items():
        out = ANDROID_RES / folder
        icon = resize(transparent, size)
        save_png(icon, out / 'ic_launcher.png')
        # roundIcon — même silhouette Afrique
        save_png(icon, out / 'ic_launcher_round.png')

    # Adaptive icon layers (foreground 108dp baseline → xxxhdpi 432)
    fg_sizes = {
        'drawable-mdpi': 108,
        'drawable-hdpi': 162,
        'drawable-xhdpi': 216,
        'drawable-xxhdpi': 324,
        'drawable-xxxhdpi': 432,
    }
    for folder, size in fg_sizes.items():
        save_png(resize(foreground, size), ANDROID_RES / folder / 'ic_launcher_foreground.png')

    anydpi = ANDROID_RES / 'mipmap-anydpi-v26'
    anydpi.mkdir(parents=True, exist_ok=True)
    (anydpi / 'ic_launcher.xml').write_text(
        '''<?xml version="1.0" encoding="utf-8"?>
<adaptive-icon xmlns:android="http://schemas.android.com/apk/res/android">
    <background android:drawable="@color/ic_launcher_background"/>
    <foreground android:drawable="@drawable/ic_launcher_foreground"/>
</adaptive-icon>
''',
        encoding='utf-8',
    )
    (anydpi / 'ic_launcher_round.xml').write_text(
        '''<?xml version="1.0" encoding="utf-8"?>
<adaptive-icon xmlns:android="http://schemas.android.com/apk/res/android">
    <background android:drawable="@color/ic_launcher_background"/>
    <foreground android:drawable="@drawable/ic_launcher_foreground"/>
</adaptive-icon>
''',
        encoding='utf-8',
    )

    values = ANDROID_RES / 'values'
    values.mkdir(parents=True, exist_ok=True)
    colors = values / 'colors.xml'
    # Fond transparent via couleur #00000000 pour laisser apparaître la silhouette Afrique
    # (le launcher applique toujours un masque cercle/squircle, mais hors silhouette = fond d'écran).
    colors.write_text(
        '''<?xml version="1.0" encoding="utf-8"?>
<resources>
    <color name="ic_launcher_background">#00000000</color>
</resources>
''',
        encoding='utf-8',
    )
    print(f'  {colors.relative_to(ROOT)}')


def write_ios(ios_master: Image.Image) -> None:
    # (filename, pixel size)
    specs = [
        ('Icon-App-20x20@1x.png', 20),
        ('Icon-App-20x20@2x.png', 40),
        ('Icon-App-20x20@3x.png', 60),
        ('Icon-App-29x29@1x.png', 29),
        ('Icon-App-29x29@2x.png', 58),
        ('Icon-App-29x29@3x.png', 87),
        ('Icon-App-40x40@1x.png', 40),
        ('Icon-App-40x40@2x.png', 80),
        ('Icon-App-40x40@3x.png', 120),
        ('Icon-App-60x60@2x.png', 120),
        ('Icon-App-60x60@3x.png', 180),
        ('Icon-App-76x76@1x.png', 76),
        ('Icon-App-76x76@2x.png', 152),
        ('Icon-App-83.5x83.5@2x.png', 167),
        ('Icon-App-1024x1024@1x.png', 1024),
    ]
    for name, size in specs:
        save_png(resize(ios_master, size).convert('RGB'), IOS_SET / name)


def write_web(ios_master: Image.Image, transparent: Image.Image) -> None:
    WEB_ICONS.mkdir(parents=True, exist_ok=True)
    save_png(resize(ios_master, 192), WEB_ICONS / 'Icon-192.png')
    save_png(resize(ios_master, 512), WEB_ICONS / 'Icon-512.png')
    # Maskable: garder marge + fond navy
    save_png(resize(ios_master, 192), WEB_ICONS / 'Icon-maskable-192.png')
    save_png(resize(ios_master, 512), WEB_ICONS / 'Icon-maskable-512.png')
    save_png(resize(transparent.convert('RGBA'), 32).convert('RGBA'), WEB_FAVICON)


def write_splash(ios_master: Image.Image) -> None:
    # Image centrée pour le splash Android / iOS
    splash = resize(ios_master, 288)
    save_png(splash, ANDROID_RES / 'drawable' / 'splash_logo.png')
    launch_set = ROOT / 'ios' / 'Runner' / 'Assets.xcassets' / 'LaunchImage.imageset'
    save_png(resize(ios_master, 168), launch_set / 'LaunchImage.png')
    save_png(resize(ios_master, 336), launch_set / 'LaunchImage@2x.png')
    save_png(resize(ios_master, 504), launch_set / 'LaunchImage@3x.png')


def main() -> None:
    transparent = Image.open(BRAND / 'app_icon_transparent.png').convert('RGBA')
    foreground = Image.open(BRAND / 'app_icon_foreground.png').convert('RGBA')
    ios_master = Image.open(BRAND / 'app_icon_ios.png').convert('RGBA')

    print('Android…')
    write_android(transparent, foreground)
    print('iOS…')
    write_ios(ios_master)
    print('Web…')
    write_web(ios_master, transparent)
    print('Splash…')
    write_splash(ios_master)
    print('OK')


if __name__ == '__main__':
    main()
