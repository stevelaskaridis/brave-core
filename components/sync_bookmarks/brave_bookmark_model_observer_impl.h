/* Copyright 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_SYNC_BOOKMARKS_BRAVE_BOOKMARK_MODEL_OBSERVER_IMPL_H_
#define BRAVE_COMPONENTS_SYNC_BOOKMARKS_BRAVE_BOOKMARK_MODEL_OBSERVER_IMPL_H_

#include "components/sync_bookmarks/bookmark_model_observer_impl.h"

namespace sync_bookmarks {

class BraveBookmarkModelObserverImpl : public BookmarkModelObserverImpl {
 public:
  // |bookmark_tracker_| must not be null and must outlive this object.
  BraveBookmarkModelObserverImpl(
      const base::RepeatingClosure& nudge_for_commit_closure,
      base::OnceClosure on_bookmark_model_being_deleted_closure,
      SyncedBookmarkTracker* bookmark_tracker);
  ~BraveBookmarkModelObserverImpl() override;

  // BookmarkModelObserver:
  void BookmarkMetaInfoChanged(bookmarks::BookmarkModel* model,
                               const bookmarks::BookmarkNode* node) override;
  void BookmarkNodeFaviconChanged(bookmarks::BookmarkModel* model,
                                  const bookmarks::BookmarkNode* node) override;
 private:
  DISALLOW_COPY_AND_ASSIGN(BraveBookmarkModelObserverImpl);
};

}  // namespace sync_bookmarks

#endif  // BRAVE_COMPONENTS_SYNC_BOOKMARKS_BRAVE_BOOKMARK_MODEL_OBSERVER_IMPL_H_
