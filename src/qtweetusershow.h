/* Copyright (c) 2010, Antonie Jovanoski
 *
 * All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 *
 * Contact e-mail: Antonie Jovanoski <minimoog77_at_gmail.com>
 */

#ifndef QTWEETUSERSHOW_H
#define QTWEETUSERSHOW_H

#include "qtweetnetbase.h"

/*!
    Class for fetching extended information for given user
 */
class QTWEETLIBSHARED_EXPORT QTweetUserShow : public QTweetNetBase
{
    Q_OBJECT
public:
    QTweetUserShow(QObject *parent = 0);
    QTweetUserShow(OAuthTwitter *oauthTwitter, QObject *parent = 0);
    void fetch(qint64 id = 0,
               qint64 userid = 0,
               const QString& screenName = QString(),
               ResponseType respType = QTweetNetBase::JSON);

signals:
    /*! Emited when json is parsed to user info */
    void parsedUserInfo(const QTweetUser& userInfo);

protected slots:
    void parsingJsonFinished(const QVariant &json, bool ok, const QString &errorMsg);

private slots:
    void error();
};

#endif // QTWEETUSERSHOW_H