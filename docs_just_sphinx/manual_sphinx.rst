Pure Sphinx Documentation
=========================

.. cpp:namespace-push:: simgrid::s4u

.. cpp:class:: Actor

   A class that acts on things.

   .. cpp:type:: aid_t = int

      Type definition for making this valid code.

   .. cpp:function:: Actor()

      Default constructor, does nothing.

   .. cpp:function:: ~Actor()

      Default destructor, does nothing.

   .. cpp:function:: void kill()

      Kills the actor?

   .. cpp:function:: static void kill(aid_t pid)

      Kills the actor specified by the given pid.

.. cpp:namespace-pop::
