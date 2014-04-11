/*  Copyright 2014 MaidSafe.net limited

    This MaidSafe Software is licensed to you under (1) the MaidSafe.net Commercial License,
    version 1.0 or later, or (2) The General Public License (GPL), version 3, depending on which
    licence you accepted on initial access to the Software (the "Licences").

    By contributing code to the MaidSafe Software, or to this project generally, you agree to be
    bound by the terms of the MaidSafe Contributor Agreement, version 1.0, found in the root
    directory of this project at LICENSE, COPYING and CONTRIBUTOR respectively and also
    available at: http://www.maidsafe.net/licenses

    Unless required by applicable law or agreed to in writing, the MaidSafe Software distributed
    under the GPL Licence is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS
    OF ANY KIND, either express or implied.

    See the Licences for the specific language governing permissions and limitations relating to
    use of the MaidSafe Software.                                                                 */

#include "maidsafe/session_handler.h"

#include "maidsafe/common/test.h"
#include "maidsafe/routing/parameters.h"

#include "maidsafe/anonymous_session.h"
#include "maidsafe/common/authentication/user_credentials.h"


namespace maidsafe {

namespace test {

// Pre-condition : Need a Vault network running
TEST(SessionHandlerTest, BEH_Constructor) {
  routing::Parameters::append_local_live_port_endpoint = true;
  BootstrapInfo bootstrap_info;
  {
     SessionHandler<AnonymousSession> session_handler(bootstrap_info);
  }
  {
    passport::Anmaid anmaid;
    passport::Maid maid(anmaid);
    Client client(maid, anmaid, bootstrap_info);
    AnonymousSession session;
    authentication::UserCredentials user_credentials;

    SessionHandler<AnonymousSession> session_handler(std::move(session), client,
                                                     std::move(user_credentials));
  }
}

}  // namespace test

}  // namespace maidsafe
