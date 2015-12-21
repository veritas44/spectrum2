---
layout: page
title: Spectrum 2
---

### Description

Libpurple backend is backend based on Librpurple library supporting all the networks supported by libpurple.

### Configuration

You have to choose this backend in Spectrum 2 configuration file to use it:

	[service]
	backend=/usr/bin/spectrum2_libpurple_backend

There is also special configuration variable in "service" called @protocol@ which decides which Libpurple's protocol will be used:

Protocol variable| Description
-----------------|------------
prpl-jabber| Jabber
prpl-aim|AIM
prpl-icq|ICQ
prpl-msn|MSN
prpl-yahoo|Yahoo
prpl-gg|Gadu Gadu
prpl-novell|Groupwise

### Third-party plugins

Spectrum 2 should work with any third-party libpurple plugin which is properly installed. For example, popular plugins:

Protocol variable| website | Description
-----------------|------------
prpl-facebook| [https://github.com/jgeboski/purple-facebook](website) | Facebook
prpl-telegram| [https://github.com/majn/telegram-purple](website) | Telegram
prpl-skypeweb| [https://github.com/EionRobb/skype4pidgin/tree/master/skypeweb](website) | Skype

These plugins are included by default in our Docker image.