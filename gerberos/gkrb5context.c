/* Gerberos - Kerberos GLib bindings
 *
 * Copyright (C) 2009 Gergely Polonkai
 *
 */

#include <krb5.h>

#include "gkrb5context.h"

#undef g_krb5_context

G_DEFINE_ABSTRACT_TYPE (GKrb5Context, g_krb5_context, G_TYPE_OBJECT);

struct _GKrb5ContextPrivate {
	krb5_context kerberos_context;

	GMainContext *context;
};

static void
g_krb5_context_set_property (GObject *object, guint prop_id, const GValue *value, GParamSpec *pspec)
{
	GKrb5Context *kerberos_context;

	kerberos_context = G_KRB5_CONTEXT(object);

	switch (prop_id)
	{
		default:
			G_OBJECT_WARN_INVALID_PROPERTY_ID(object, prop_id, pspec);
			break;
	}
}

static void
g_krb5_context_get_property (GObject *object, guint prop_id, GValue *value, GParamSpec *pspec)
{
	GKrb5Context *kerberos_context;
	GKrb5ContextPrivate *priv;

	switch (prop_id)
	{
		default:
			G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
			break;
	}
}

static guint signals[LAST_SIGNAL] = { 0 };

static void
g_krb5_context_finalize (GObject *object)
{
	GKrb5Context *kerberos_context;

	kerberos_context = G_KRB5_CONTEXT(object);

	if (kerberos_context->priv->context)
		g_main_context_unref(kerberos_context->priv->context);

	G_OBJECT_CLASS(g_krb5_context_parent_class)->finalize(object);
}

static void
g_krb5_context_dispose(GObject *object)
{
	GKrb5Context *kerberos_context;
	GKrb5Context *priv;

	kerberos_context = G_KRB5_CONTEXT(object);
	priv = kerberos_context->priv;

	G_OBJECT_CLASS(g_krb5_context_parent_class)->dispose(object);
}

static void
g_krb5_context_class_init(GKrb5ContextClass *klass)
{
	GObjectClass *object_class;

	g_type_class_add_private(klass, sizeof(GKrb5ContextPrivate));

	object_class = G_OBJECT_CLASS(klass);
	object_class->finalize = g_krb5_context_finalize;
	object_class->dispose = g_krb5_context_dispose;
	object_class->get_property = g_krb5_context_get_property;
	object_class->set_property = g_krb5_context_set_property;
}

static void
g_krb5_context_init(GKrb5Context *kerberos_context)
{
	kerberos_context->priv = G_TYPE_INSTANCE_GET_PRIVATE(kerberos_context, G_TYPE_KRB5_CONTEXT, GKrb5ContextPrivate);
	kertberos_context->priv->context = g_main_context_get_thread_default();
}

