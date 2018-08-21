#pragma once

/// The simgrid namespace contains everything.
namespace simgrid {
    /// The namespace s4u contains other things.
    namespace s4u {
        /// A class that acts on things.
        class Actor {
        public:
            /// Type definition for making this valid code.
            using aid_t = int;

            /// Default constructor, does nothing.
            Actor() { }

            /// Default destructor, does nothing.
            ~Actor() { }

            /// Kills the actor?
            void kill();

            /// Kills the actor specified by the given pid.
            static void kill(aid_t pid);
        };
    }// namespace s4u
}// namespace simgrid
