#!/bin/bash
# for disabling codecs/techniques

./configure \
--extra-cflags=-I/usr/local/include \
--extra-ldflags=-L/usr/local/lib \
--libdir=/c/source/notqvix/ffmpeg-19751/ffmpeg/lib \
--incdir=/c/source/notqvix/ffmpeg-19751/ffmpeg/include \
--bindir=/c/source/notqvix/ffmpeg-19751/ffmpeg/ \
--shlibdir=/c/source/notqvix/ffmpeg-19751/ \
--enable-memalign-hack \
--target-os=mingw32 \
--enable-shared \
--disable-static \
--disable-ffserver \
--disable-ffplay \
--disable-ipv6 \
--disable-devices \
--disable-swscale-alpha \
--disable-network \
--disable-debug \
--disable-encoders \
--disable-decoders \
--disable-demuxers \
--disable-muxers \
--disable-parsers  \
--enable-libmp3lame \
--enable-encoder=h263 \
--enable-encoder=flv \
--enable-encoder=h263p \
--enable-encoder=h264 \
--enable-encoder=snow \
--enable-encoder=mpeg1video \
--enable-encoder=mp2 \
--enable-encoder=vc1 \
--enable-encoder=png \
--enable-encoder=rawvideo \
--enable-encoder=mjpeg \
--enable-encoder=pcm_s16le \
--enable-encoder=pcm_s16be \
--enable-encoder=pcm_s8 \
--enable-encoder=pcm_u16le \
--enable-encoder=pcm_u16be \
--enable-encoder=pcm_u8 \
--enable-encoder=flac \
--enable-encoder=libmp3lame \
--enable-decoder=h263 \
--enable-decoder=flv \
--enable-decoder=h264 \
--enable-decoder=snow \
--enable-decoder=mpegvideo \
--enable-decoder=mpeg1video \
--enable-decoder=vc1 \
--enable-decoder=png \
--enable-decoder=rawvideo \
--enable-decoder=mjpeg \
--enable-decoder=mp2 \
--enable-decoder=pcm_s16le \
--enable-decoder=pcm_s16be \
--enable-decoder=pcm_s8 \
--enable-decoder=pcm_u16le \
--enable-decoder=pcm_u16be \
--enable-decoder=pcm_u8 \
--enable-decoder=flac \
--enable-decoder=mp3 \
--enable-muxer=mpeg1system \
--enable-muxer=mpeg1vcd \
--enable-muxer=mpeg1video \
--enable-muxer=h263 \
--enable-muxer=h264 \
--enable-muxer=mp4 \
--enable-muxer=mov \
--enable-muxer=mp2 \
--enable-muxer=avi \
--enable-muxer=flv \
--enable-muxer=mjpeg \
--enable-muxer=flac \
--enable-muxer=wav \
--enable-muxer=mpegps \
--enable-muxer=pcm_s16le \
--enable-muxer=pcm_s16be \
--enable-muxer=pcm_s8 \
--enable-muxer=pcm_u16le \
--enable-muxer=pcm_u16be \
--enable-muxer=pcm_u8 \
--enable-muxer=mp3 \
--enable-muxer=asf \
--enable-demuxer=h263 \
--enable-demuxer=h264 \
--enable-demuxer=mpegvideo \
--enable-demuxer=mpegps \
--enable-demuxer=avi \
--enable-demuxer=mp4 \
--enable-demuxer=mov \
--enable-demuxer=flac \
--enable-demuxer=wav \
--enable-demuxer=flv \
--enable-demuxer=mjpeg \
--enable-demuxer=vc1 \
--enable-demuxer=pcm_s16le \
--enable-demuxer=pcm_s16be \
--enable-demuxer=pcm_s8 \
--enable-demuxer=pcm_u16le \
--enable-demuxer=pcm_u16be \
--enable-demuxer=pcm_u8 \
--enable-demuxer=mp3 \
--enable-demuxer=asf \
--enable-demuxer=rawvideo \
--enable-parser=h263 \
--enable-parser=vc1 \
--enable-parser=h264 \
--enable-parser=mpegaudio \
--enable-parser=mpegvideo \
--enable-parser=mpeg4video \
--enable-parser=mjpeg \
--enable-parser=ac3 \
--enable-parser=eac3 \
--enable-encoder=mpeg2video \
--enable-encoder=ac3 \
--enable-decoder=mpeg2video \
--enable-decoder=ac3 \
--enable-decoder=eac3 \
--enable-muxer=mpeg2vob \
--enable-muxer=mpeg2svcd \
--enable-muxer=mpeg2video \
--enable-muxer=mpeg2dvd \
--enable-muxer=ac3 \
--enable-demuxer=ac3 \
--enable-encoder=mpeg4 \
--enable-decoder=mpeg4 \
--enable-encoder=wmv1 \
--enable-encoder=wmv2 \
--enable-decoder=wmv1 \
--enable-decoder=wmv2 \

