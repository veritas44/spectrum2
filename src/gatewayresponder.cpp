/**
 * XMPP - libpurple transport
 *
 * Copyright (C) 2009, Jan Kaluza <hanzz@soc.pidgin.im>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02111-1301  USA
 */

#include "transport/gatewayresponder.h"

#include <iostream>
#include <boost/bind.hpp>
#include "Swiften/Queries/IQRouter.h"
#include "Swiften/Elements/RawXMLPayload.h"
#include "Swiften/Swiften.h"
#include "transport/usermanager.h"
#include "transport/user.h"
#include "transport/transport.h"
#include "transport/logging.h"

using namespace Swift;
using namespace boost;

namespace Transport {

DEFINE_LOGGER(logger, "GatewayResponder");

GatewayResponder::GatewayResponder(Swift::IQRouter *router, UserManager *userManager) : Swift::Responder<GatewayPayload>(router) {
	m_userManager = userManager;
}

GatewayResponder::~GatewayResponder() {
}

bool GatewayResponder::handleGetRequest(const Swift::JID& from, const Swift::JID& to, const std::string& id, boost::shared_ptr<Swift::GatewayPayload> payload) {
	sendResponse(from, id, boost::shared_ptr<GatewayPayload>(new GatewayPayload(Swift::JID(), "Enter legacy network contact ID.", "Contact ID")));
	return true;
}

bool GatewayResponder::handleSetRequest(const Swift::JID& from, const Swift::JID& to, const std::string& id, boost::shared_ptr<Swift::GatewayPayload> payload) {
	std::string prompt = payload->getPrompt();
	std::string escaped = Swift::JID::getEscapedNode(prompt);
	std::string jid = escaped + "@" + m_userManager->getComponent()->getJID().toBare().toString();
	
	sendResponse(from, id, boost::shared_ptr<GatewayPayload>(new GatewayPayload(jid)));
	return true;
}

}
